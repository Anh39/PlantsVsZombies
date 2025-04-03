#pragma once
#include "node.h"
#include "../graphic.h"


class Scene {
public:
    static int instanceCount;

    /// @brief Global renderer
    static Renderer* renderer;
    /// @brief Global window
    static Window* window;
    /// @brief Root node of Scene
    Node* root;
    /// @brief Current scene
    static Scene* current;
    static Vector2 scale;

    Scene();
    ~Scene();
    /// @brief Used to process frame update, draw, collide, ... Called by GameLoop
    /// @param delta 
    void ProcessFrame(float delta);
    /// @brief Set as current scene for update
    void SetAsCurrentScene();
    /// @brief Get class debug info
    static std::string GetDebugInfo() {
        return "Instance count " + std::to_string(Scene::instanceCount);
    }
private:
    void OnWindowResized(const Vector2& size);
};
