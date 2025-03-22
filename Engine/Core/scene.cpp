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

Scene::Scene() {
    this->window = new Window();
    this->window->sdlWindow = InitSDL();
    this->renderer = new Renderer();
    this->renderer->sdlRenderer = createRenderer(this->window->sdlWindow);
    this->root = new Node();
}
void Scene::SetAsCurrentScene() {
    Texture::setCurrentRenderer(this->renderer);
    this->current = this;
}
void Scene::Render() {
    Node* root = Scene::root;
    Renderer* renderer = this->renderer;
    SDL_SetRenderDrawColor(renderer->sdlRenderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer->sdlRenderer);
    // cout << "Rendering ..." << endl;
    // if (root == nullptr) {
    //     cout << "Null root" << endl;
    // }
    queue<pair<Node*, int>> travelQueue;
    queue<Node*> updateQueue;
    queue<Node*> renderQueue;
    queue<Node*> markedForDelete;
    vector<Node*> collideInvoker;
    vector<Node*> collideReceiver;
    
    travelQueue.push(make_pair(root, 0));
    string log = "";
    bool isLogging = false;
    bool isDebugging = false;
    if (KeyboardEvent::JustPressed(KeyboardType::F1)) {
        isLogging = true;
    }

    if (!isLogging && KeyboardEvent::IsPressing(KeyboardType::F1)) {
        isDebugging = true;
    }

    while (!travelQueue.empty())
    {
        auto front = travelQueue.front();
        Node* current = front.first;
        int level = front.second;
        travelQueue.pop();
        if (current == nullptr) {
            continue;
        }
        if (isLogging) {
            string prefix = "";
            for(int i=0; i<level; i++) {
                prefix += "-";
            }
            log += prefix + current->Info();
        }
        int size = current->children.size();
        for(int i=0; i<size; i++) {
            travelQueue.push(make_pair(current->children[i], level+1));
        }
        if (current->isDeleted) {
            markedForDelete.push(current);
        }
        if (current->collideMask) {
            collideInvoker.push_back(current);
        }
        if (current->collideFilter) {
            collideReceiver.push_back(current);
        }
        renderQueue.push(current);
        updateQueue.push(current);
    }
    
    if (isDebugging) {
        cout << "Travel completed" << endl;
    }

    while (!updateQueue.empty())
    {
        Node* current = updateQueue.front();
        updateQueue.pop();
        current->Update(DELAY_TIME/1000);
    }
    if (isDebugging) {
        cout << "Update completed" << endl;
    }
    while (!renderQueue.empty())
    {
        Node* current = renderQueue.front();
        renderQueue.pop();
        current->Draw(renderer, current->GetAbsolutePosition());
    }
    if (isDebugging) {
        cout << "Render completed" << endl;
    }
    int invokerSize = collideInvoker.size();
    int receiverSize = collideReceiver.size();
    for(int i=0; i<invokerSize; i++) {
        Node* invoker = collideInvoker[i];
        Rect invokerRect = invoker->rect;
        Vector2F invokerAbsolutePosition = invoker->GetAbsolutePosition();
        invokerRect.x = invokerAbsolutePosition.x;
        invokerRect.y = invokerAbsolutePosition.y;
        for(int j=0; j<receiverSize; j++) {
            Node* receiver = collideReceiver[j];
            if (invoker->collideMask & receiver->collideFilter ) {
                Rect receiverRect = receiver->rect;
                Vector2F receiverAbsolutePosition = receiver->GetAbsolutePosition();
                receiverRect.x = receiverAbsolutePosition.x;
                receiverRect.y = receiverAbsolutePosition.y;
                if (invokerRect.intersect(receiverRect)) {
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
    
    // while (!Node::MarkedForDelete.empty())
    // {
    //     Node* node = Node::MarkedForDelete.front();
    //     Node::MarkedForDelete.pop();
    //     if (node != nullptr) {
    //         delete node;
    //     }
    // }


    if (isDebugging) {
        cout << "Collision completed" << endl;
    }
    if (isLogging) {
        cout << "--------------------" << endl;
        cout << log << endl;
        cout << "--------------------" << endl;
    }
    // cout << "Render completed !" << endl;
    SDL_RenderPresent(renderer->sdlRenderer);
}

