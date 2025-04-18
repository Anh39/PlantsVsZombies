#include "node.h"
#include <random>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int Node::instanceCount = 0;

Node::Node() {
    Node::instanceCount++;
    this->Name = "Node";
    this->id = GenerateId();
    this->position = Vector2();
    this->children = vector<Node*>();
};
Node::~Node() {
    Node::instanceCount--;
}
void Node::Delete() {
    if (this->parent != nullptr) {
        this->parent->RemoveChildren(this);
    }
    this->isDeleted = true;
    for (auto child : this->children)
    {
        child->Delete();
    }
}
void Node::Update(float delta) {

}
string Node::Info() {
    return "Name " + string(this->Name) + " | Id " + string(this->id);
}
string Node::Serialize() {
    return string("Empty");
}
const char* Node::GenerateId() {
    int randomNumber = rand();
    string str = to_string(randomNumber);
    int strSize = str.size() + 1;
    const char* generated_id = new char[strSize];
    copy(str.c_str(), str.c_str() + strSize, const_cast<char*>(generated_id));
    return generated_id;
};

void Node::AddChildren(Node* child) {
    child->parent = this;
    // cout << "A" << endl;
    this->children.push_back(child);
    // cout << "B" << endl;
}
Node* Node::GetChild(string name) {
    for (Node* child : this->children)
    {
        if (child->Name == name) {
            return child;
        }
    }
    return nullptr;
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
        this->parent->RemoveChildren(this);
    }
    par->AddChildren(this);
}
Vector2 Node::GetAbsolutePosition() {
    Vector2 absPosition = this->position;
    Node* parent = this->parent;
    while (parent != nullptr)
    {
        Vector2 parentRelativePosition = parent->position;
        absPosition.x += parentRelativePosition.x;
        absPosition.y += parentRelativePosition.y;
        parent = parent->parent;
        // parent = nullptr;
        // break;
    }
    return absPosition;
}
void Node::SetAbsolutePosition(Vector2 pos) {
    Vector2 absPosition = this->GetAbsolutePosition();
    this->position = pos-absPosition;
}

