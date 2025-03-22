#pragma once
#include <vector>
#include <SDL2/SDL_image.h>
#include "../dataTypes.h"
#include "../graphic.h"
#include <iostream>
#include <queue>

using namespace std;
enum CollideMask 
{
    Layer1 = 0x1,
    Layer2 = 0x10,
    Layer3 = 0x100,
    Layer4 = 0x1000,
    Layer5 = 0x10000,
    Layer6 = 0x100000,
    Layer7 = 0x1000000,
    Layer8 = 0x10000000
};


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

    void SetPosition(Vector2F position);
    Vector2F GetPosition();
    void SetSize(Vector2 size);
    Vector2 GetSize();
    void SetAbsolutePosition(Vector2F abosulePosition);
    Vector2F GetAbsolutePosition();

    virtual void OnCollide(Node* other);
    virtual void OnCollided(Node* other);
    virtual void Draw(Renderer* renderer, Vector2F absolutePosition);
    virtual void Update(float delta);
    virtual ~Node();
    virtual string Info();
    virtual string Serialize();
    virtual void Delete();

    virtual const string GetClassName() { return "Node"; }
private:
    const char* GenerateId();
};