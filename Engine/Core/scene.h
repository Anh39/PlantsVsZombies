#pragma once
#include "node.h"
#include "../graphic.h"

#define DELAY_TIME 40.0

using namespace std;
class Scene {
public:
    Renderer* renderer;
    Window* window;
    Node* root;

    static Scene* current;

    Scene();
    void Render();
    void SetAsCurrentScene();
};
