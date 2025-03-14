#pragma once
#include <vector>
#include <SDL2/SDL_image.h>
#include "../dataTypes.h"
#include "../graphic.h"

using namespace std;
class Node 
{
public:
    const char* className = "Node";

    Rect rect;
    const char* id;

    bool isVisible;
    bool isDirty;
    Node* parent;

    vector<Node*> children;

    Node();
    void AddChildren(Node* child);
    void RemoveChildren(Node* child);
    void SetParent(Node* par);

    void setPosition(Vector2F position);
    Vector2F getPosition();
    void setSize(Vector2 size);
    Vector2 getSize();
    void setAbsolutePosition(Vector2F abosulePosition);
    Vector2F getAbsolutePosition();

    virtual void draw(Renderer* renderer, Vector2F absolutePosition);
    virtual void update(float delta);
    virtual ~Node();
private:
    const char* generateId();
};