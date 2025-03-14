#include "scene.h"
#include <random>
#include <string>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

Scene::Scene() {
    this->window = new Window();
    this->window->sdlWindow = initSDL();
    this->renderer = new Renderer();
    this->renderer->sdlRenderer = createRenderer(this->window->sdlWindow);
    this->root = new Node();
}
void Scene::setAsCurrentScene() {
    Texture::setCurrentRenderer(this->renderer);
}
void Scene::render() {
    Node* root = Scene::root;
    Renderer* renderer = this->renderer;
    SDL_SetRenderDrawColor(renderer->sdlRenderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer->sdlRenderer);
    // cout << "Rendering ..." << endl;
    // if (root == nullptr) {
    //     cout << "Null root" << endl;
    // }
    queue<Node*> travelQueue;
    queue<Node*> updateQueue;
    queue<Node*> renderQueue;
    travelQueue.push(root);
    while (!travelQueue.empty())
    {
        Node* current = travelQueue.front();
        travelQueue.pop();
        renderQueue.push(current);
        updateQueue.push(current);
        if (current == nullptr) {
            continue;
        }
        int size = current->children.size();
        for(int i=0; i<size; i++) {
            travelQueue.push(current->children[i]);
        }
    }
    while (!updateQueue.empty())
    {
        Node* current = updateQueue.front();
        updateQueue.pop();
        current->update(DELAY_TIME/1000);
    }
    while (!renderQueue.empty())
    {
        Node* current = renderQueue.front();
        renderQueue.pop();
        current->draw(renderer, current->getAbsolutePosition());
    }

    // cout << "Render completed !" << endl;
    SDL_RenderPresent(renderer->sdlRenderer);
}

