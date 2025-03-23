#pragma once
#include "node.h"
#include "../graphic.h"


using namespace std;
class Scene {
public:
    Renderer* renderer;
    Window* window;
    Node* root;
    static Scene* current;

    Scene();
    ~Scene();
    void ProcessFrame(float delta);
    void SetAsCurrentScene();
    
};
