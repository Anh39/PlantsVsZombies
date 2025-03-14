#pragma once
#include <vector>
#include "node.h"
#include "../graphic.h"

#define DELAY_TIME 40.0

using namespace std;
class Scene {
public:
    Renderer* renderer;
    Window* window;
    Node* root;

    Scene();
    void render();
    void setAsCurrentScene();
};
