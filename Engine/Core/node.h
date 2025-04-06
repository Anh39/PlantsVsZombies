#pragma once
#include <vector>
#include "../dataTypes.h"
#include <iostream>

/// @brief Function mask for node features, internal use only
enum NodeFeatureMask
{
    BASIC_NODE = 0b1,
    RENDER_NODE = 0b10,
    COLLIDE_NODE = 0b100,
    EVENT_NODE = 0b1000,
};
/// @class Node
/// @brief Base class for all Game Object. Should override Update, Draw, OnCollide, OnCollided.
class Node 
{
public:
    static int instanceCount;
    /// @brief Feature mask of node, for internal use only
    unsigned int feature = NodeFeatureMask::BASIC_NODE;

    Node();
    virtual ~Node();
    /// @brief Name of node
    std::string Name;
    /// @brief Relative position of node
    Vector2 position;
    /// @brief Parent of this in Scene, should be nullptr if it's root.
    Node* parent = nullptr;
    /// @brief Children of this node in Scene.
    std::vector<Node*> children;
    /// @brief Id for identify, currently no use.
    const char* id;
    /// @brief Visible of Node, not implemented.
    bool isVisible = true;
    /// @brief Dirty flag for render optimize, not implemented.
    bool isDirty = true;
    /// @brief Mark if this node should be deleted at the end of frame.
    bool isDeleted = false;

    /// @brief Add a child to this node. Auto assign child parent.
    void AddChildren(Node* child);
    /// @brief Remove child from this node. Auto remove child parent.
    void RemoveChildren(Node* child);
    /// @brief Set parent of this node. Auto add as child to parent.
    void SetParent(Node* par);
    /// @brief Get children with name, return nullptr if not found
    Node* GetChild(std::string name);

    /// @brief Set absolute position of Rect of this node.
    void SetAbsolutePosition(Vector2 abosulePosition);
    /// @brief Get absolute position of Rect of this node.
    Vector2 GetAbsolutePosition();

    /// @brief Update function to change Node behaviour.
    virtual void Update(float delta);    
    /// @brief Get basic info for debug purpose
    virtual std::string Info();
    /// @brief Serialize for saving and loading. Not implemented.
    virtual std::string Serialize();
    /// @brief Use this to delete node. Will delete node at the end of frame.
    virtual void Delete();
    /// @brief Get class debug info
    static std::string GetDebugInfo() {
        return "Instance count " + std::to_string(Node::instanceCount);
    }
private:
    /// @brief Generate Node id;
    const char* GenerateId();
};