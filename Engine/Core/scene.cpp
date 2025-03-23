#include "scene.h"
#include <random>
#include <string>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include "../event.h"
#include <iostream>

using namespace std;

Scene* Scene::current = nullptr;
Window* Scene::window = new Window("Game", Vector2(800, 600));
Renderer* Scene::renderer = new Renderer(Scene::window);
int Scene::instanceCount = 0;

Scene::Scene() {
    this->root = new Node();
    Scene::instanceCount++;
}
Scene::~Scene() {
    Scene::instanceCount--;
    Node* root = Scene::root;
    Renderer* renderer = this->renderer;
    SDL_SetRenderDrawColor(renderer->SDL(), 0, 0, 0, 255);
    SDL_RenderClear(renderer->SDL());

    queue<pair<Node*, int>> travelQueue;
    queue<Node*> markedForDelete;
    
    travelQueue.push(make_pair(root, 0));
    while (!travelQueue.empty())
    {
        auto front = travelQueue.front();
        Node* current = front.first;
        int level = front.second;
        travelQueue.pop();
        if (current == nullptr) continue;
        int size = current->children.size();
        for(int i=0; i<size; i++) {
            travelQueue.push(make_pair(current->children[i], level+1));
        }
        markedForDelete.push(current);
    }
    while (!markedForDelete.empty())
    {
        Node* node = markedForDelete.front();
        markedForDelete.pop();
        delete node;
    }
}
void Scene::SetAsCurrentScene() {
    // Texture::SetCurrentRenderer(this->renderer);
    this->current = this;
}
void Scene::ProcessFrame(float delta) {
    Node* root = Scene::root;
    Renderer* renderer = this->renderer;
    SDL_SetRenderDrawColor(renderer->SDL(), 0, 0, 0, 255);
    SDL_RenderClear(renderer->SDL());


    queue<pair<Node*, int>> travelQueue;
    queue<Node*> updateQueue;
    queue<Node*> renderQueue;
    queue<Node*> markedForDelete;
    vector<Node*> collideInvoker;
    vector<Node*> collideReceiver;
    
    travelQueue.push(make_pair(root, 0));
    string log = "";
    bool isLogging = false;
    if (KeyboardEvent::JustPressed(KeyboardType::F1)) isLogging = true;
    while (!travelQueue.empty())
    {
        auto front = travelQueue.front();
        Node* current = front.first;
        int level = front.second;
        travelQueue.pop();
        if (current == nullptr) continue;
        if (isLogging) {
            string prefix = "";
            for(int i=0; i<level; i++) {
                prefix += "-";
            }
            log += prefix + current->Info() + "\n";
        }
        int size = current->children.size();
        for(int i=0; i<size; i++) {
            travelQueue.push(make_pair(current->children[i], level+1));
        }
        if (current->isDeleted) markedForDelete.push(current);
        if (current->collideMask) collideInvoker.push_back(current);
        if (current->collideFilter) collideReceiver.push_back(current);
        renderQueue.push(current);
        updateQueue.push(current);
    }
    try {
        while (!updateQueue.empty())
        {
            Node* current = updateQueue.front();
            updateQueue.pop();
            current->Update(delta);
        }
    } catch (exception &e) {
        cout << "Scene exit" << endl;
        cout << "Reason : " << e.what() << endl;
        return;
    }
    while (!renderQueue.empty())
    {
        Node* current = renderQueue.front();
        renderQueue.pop();
        current->Draw(renderer, current->GetAbsolutePosition());
    }
    int invokerSize = collideInvoker.size();
    int receiverSize = collideReceiver.size();
    for(int i=0; i<invokerSize; i++) {
        Node* invoker = collideInvoker[i];
        Rect invokerRect = invoker->rect;
        Vector2 invokerAbsolutePosition = invoker->GetAbsolutePosition();
        invokerRect.x = invokerAbsolutePosition.x;
        invokerRect.y = invokerAbsolutePosition.y;
        for(int j=0; j<receiverSize; j++) {
            Node* receiver = collideReceiver[j];
            if (invoker->collideMask & receiver->collideFilter ) {
                Rect receiverRect = receiver->rect;
                Vector2 receiverAbsolutePosition = receiver->GetAbsolutePosition();
                receiverRect.x = receiverAbsolutePosition.x;
                receiverRect.y = receiverAbsolutePosition.y;
                if (invokerRect.Intersect(receiverRect)) {
                    // cout << invoker->GetClassName() << "|" << receiver->GetClassName() << "|" << endl; //
                    invoker->OnCollide(receiver);
                    receiver->OnCollided(invoker);
                }
            }
        }
    }
    while (!markedForDelete.empty())
    {
        Node* node = markedForDelete.front();
        markedForDelete.pop();
        delete node;
    }
    if (isLogging) {
        cout << "-----Node tree-----" << endl;
        cout << log;
        cout << "--------End--------" << endl;
    }
    SDL_RenderPresent(renderer->SDL());
}

