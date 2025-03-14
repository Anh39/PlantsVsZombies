#include "node.h"
#include <random>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

Node::Node() {
    this->isVisible = true;
    this->isDirty = true;
    this->id = generateId();
    this->rect = Rect();
};
Node::~Node() {

}
const char* Node::generateId() {
    int randomNumber = rand();
    string str = to_string(randomNumber);
    int strSize = str.size() + 1;
    const char* generated_id = new char[strSize];
    copy(str.c_str(), str.c_str() + strSize, const_cast<char*>(generated_id));
    return generated_id;
};

void Node::AddChildren(Node* child) {
    child->parent = this;
    children.emplace_back(child);
}
void Node::RemoveChildren(Node* child) {
    child->parent = nullptr;
    int size = children.size();
    for(int i=0; i<size; i++) {
        if (children[i] == child) {
            children.erase(children.begin() + i);
            break;
        }
    }
}
void Node::SetParent(Node* par) {
    if (this->parent != nullptr) {
        parent->RemoveChildren(parent);
    }
    par->AddChildren(this);
}
void Node::draw(Renderer* renderer, Vector2F absolutePosition) {

}
void Node::update(float delta) {

}
Vector2F Node::getPosition() {
    auto x = this->rect.x;
    auto y = this->rect.y;
    return Vector2F(x, y);
}
void Node::setPosition(Vector2F pos) {
    this->rect.x = pos.x;
    this->rect.y = pos.y;
}
Vector2 Node::getSize() {
    auto w = this->rect.w;
    auto h = this->rect.h;
    return Vector2(w, h);
}
void Node::setSize(Vector2 size) {
    this->rect.w = size.x;
    this->rect.h = size.y;
}
Vector2F Node::getAbsolutePosition() {
    Vector2F absPosition = this->getPosition();
    Node* parent = this->parent;
    while (parent != nullptr)
    {
        Vector2F parentRelativePosition = parent->getPosition();
        absPosition.x += parentRelativePosition.x;
        absPosition.y += parentRelativePosition.y;
        parent = parent->parent;
        // parent = nullptr;
        // break;
    }
    return absPosition;
}
void Node::setAbsolutePosition(Vector2F pos) {
    Vector2F absPosition = this->getAbsolutePosition();
    this->setPosition(pos-absPosition);
}

