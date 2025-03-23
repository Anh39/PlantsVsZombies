#pragma once
#include <vector>
#include <SDL2/SDL_image.h>
#include "../dataTypes.h"
#include "../graphic.h"
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
/// @brief Base class for all Game Object
class Node 
{
public:
    Rect rect;
    unsigned int collideMask = 0;
    unsigned int collideFilter = 0;
    Node* parent = nullptr;
    vector<Node*> children;
    const char* id;
    bool isVisible = false;
    bool isDirty = true;
    bool isDeleted = false;

    Node();
    void AddChildren(Node* child);
    void RemoveChildren(Node* child);
    void SetParent(Node* par);

    void SetPosition(Vector2 position);
    Vector2 GetPosition();
    void SetSize(Vector2 size);
    Vector2 GetSize();
    void SetAbsolutePosition(Vector2 abosulePosition);
    Vector2 GetAbsolutePosition();

    virtual void OnCollide(Node* other);
    virtual void OnCollided(Node* other);
    virtual void Draw(Renderer* renderer, Vector2 absolutePosition);
    virtual void Update(float delta);
    virtual ~Node();
    virtual string Info();
    virtual string Serialize();
    virtual void Delete();

    virtual const string GetClassName() { return "Node"; }
private:
    const char* GenerateId();
};