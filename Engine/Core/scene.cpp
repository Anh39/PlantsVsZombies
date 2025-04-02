#include "scene.h"
#include <random>
#include <string>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
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

    bool isLogging = false;
    if (KeyboardEvent::JustPressed(KeyboardType::F1)) isLogging = true;
    if (isLogging) {
        string log = "";
        stack<pair<Node*, int>> loggingStack;
        loggingStack.push(make_pair(root, 0));
        while (!loggingStack.empty())
        {
            auto top = loggingStack.top();
            loggingStack.pop();
            Node* current = top.first;
            int level = top.second;
            if (isLogging) {
                string prefix = "";
                for(int i=0; i<level; i++) {
                    prefix += "-";
                }
                log += prefix + current->Info() + "\n";
            }
            int size = current->children.size();
            for(int i=0; i<size; i++) {
                loggingStack.push(make_pair(current->children[i], level+1));
            }
        }
        cout << "-----Node tree-----" << endl;
        cout << log;
        cout << "--------End--------" << endl;
        
    }

    

    queue<Node*> travelQueue;
    queue<Node*> updateQueue;
    queue<Node*> processEventQueue;
    queue<Node*> renderQueue;
    vector<Node*> collideInvoker;
    vector<Node*> collideReceiver;
    vector<Event*> events = EventQueue::PopAll();
    
    travelQueue.push(root);

    while (!travelQueue.empty())
    {
        Node* current = travelQueue.front();
        travelQueue.pop();
        if (current == nullptr) continue;
        int size = current->children.size();
        for(int i=0; i<size; i++) {
            travelQueue.push(current->children[i]);
        }
        if (current->collideMask) collideInvoker.push_back(current);
        if (current->collideFilter) collideReceiver.push_back(current);
        renderQueue.push(current);
        updateQueue.push(current);
        processEventQueue.push(current);
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
    while (!processEventQueue.empty())
    {
        Node* current = processEventQueue.front();
        processEventQueue.pop();
        for (Event* event : events)
        {
            current->ProcessEvent(event);
        }
        for (int i=0; i<events.size(); i++) {
            if (events[i]->handled) {
                delete events[i];
                events.erase(events.begin() + i);
                i--;
            }
        }
    }
    for (int i=0; i<events.size(); i++) {
        delete events[i];
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
    queue<Node*> markedForDelete;
    travelQueue.push(root);
    while (!travelQueue.empty())
    {
        Node* current = travelQueue.front();
        travelQueue.pop();
        int size = current->children.size();
        for(int i=0; i<size; i++) {
            travelQueue.push(current->children[i]);
        }
        if (current == nullptr) continue;
        if (current->isDeleted) markedForDelete.push(current);
    }
    while (!markedForDelete.empty())
    {
        Node* node = markedForDelete.front();
        markedForDelete.pop();
        delete node;

    }
    SDL_RenderPresent(renderer->SDL());
}

