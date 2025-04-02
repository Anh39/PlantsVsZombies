#pragma once
#include <vector>
#include <SDL2/SDL_image.h>
#include "../dataTypes.h"
#include "../graphic.h"
#include "../event.h"
#include <iostream>
#include <queue>

using namespace std;
/// @brief Mask for collision handling
enum CollideMask 
{
    CollideLayer1 = 0x1,
    CollideLayer2 = 0x10,
    CollideLayer3 = 0x100,
    CollideLayer4 = 0x1000,
    CollideLayer5 = 0x10000,
    CollideLayer6 = 0x100000,
    CollideLayer7 = 0x1000000,
    CollideLayer8 = 0x10000000
};

/// @class Node
/// @brief Base class for all Game Object. Should override Update, Draw, OnCollide, OnCollided.
class Node 
{
public:
    static int instanceCount;

    /// @brief Rectangle for render and collision management.
    Rect rect;
    /// @brief Mask which Node this should collide with
    unsigned int collideMask = 0;
    /// @brief Filter which Mask this Node should being interacte with
    unsigned int collideFilter = 0;
    /// @brief Parent of this in Scene, should be nullptr if it's root.
    Node* parent = nullptr;
    /// @brief Children of this node in Scene.
    vector<Node*> children;
    /// @brief Id for identify, currently no use.
    const char* id;
    /// @brief Visible of Node, not implemented.
    bool isVisible = false;
    /// @brief Dirty flag for render optimize, not implemented.
    bool isDirty = true;
    /// @brief Mark if this node should be deleted at the end of frame.
    bool isDeleted = false;

    Node();
    /// @brief Add a child to this node. Auto assign child parent.
    void AddChildren(Node* child);
    /// @brief Remove child from this node. Auto remove child parent.
    void RemoveChildren(Node* child);
    /// @brief Set parent of this node. Auto add as child to parent.
    void SetParent(Node* par);

    /// @brief Set relative position of Rect of this node.
    void SetPosition(Vector2 position);
    /// @brief Get relative position of Rect this Node.
    Vector2 GetPosition();
    /// @brief Set size of Rect of this node.
    virtual void SetSize(Vector2 size);
    /// @brief Get size of Rect of this node.
    Vector2 GetSize();
    /// @brief Set absolute position of Rect of this node.
    void SetAbsolutePosition(Vector2 abosulePosition);
    /// @brief Get absolute position of Rect of this node.
    Vector2 GetAbsolutePosition();

    /// @brief On collide with other node.
    virtual void OnCollide(Node* other);
    /// @brief On collided with other node.
    virtual void OnCollided(Node* other);
    /// @brief Draw function to show graphic.
    virtual void Draw(Renderer* renderer, Vector2 absolutePosition);
    /// @brief Update function to change Node behaviour.
    virtual void Update(float delta);
    /// @brief Process event
    virtual void ProcessEvent(Event* event);
    virtual ~Node();
    /// @brief Get basic info for debug purpose
    virtual string Info();
    /// @brief Serialize for saving and loading. Not implemented.
    virtual string Serialize();
    /// @brief Use this to delete node. Will delete node at the end of frame.
    virtual void Delete();
    /// @brief Get class name
    virtual const string GetClassName() { return "Node"; }
    /// @brief Get class debug info
    static string GetDebugInfo() {
        return "Instance count " + to_string(Node::instanceCount);
    }
private:
    /// @brief Generate Node id;
    const char* GenerateId();
};