#pragma once
#include "node.h"
#include "../graphic.h"


using namespace std;
class Scene {
public:
    static int instanceCount;

    static Renderer* renderer;
    static Window* window;
    Node* root;
    static Scene* current;

    Scene();
    ~Scene();
    void ProcessFrame(float delta);
    void SetAsCurrentScene();
    static string GetDebugInfo() {
        return "Instance count " + to_string(Scene::instanceCount);
    }
};
