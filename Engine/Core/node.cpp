#include "node.h"
#include <random>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int Node::instanceCount = 0;

Node::Node() {
    Node::instanceCount++;
    this->id = GenerateId();
    this->rect = Rect();
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
void Node::Draw(Renderer* renderer, Vector2 absolutePosition) {

}
void Node::Update(float delta) {

}
void Node::OnCollide(Node* other) {

}
void Node::OnCollided(Node* other) {
    
}
void Node::ProcessEvent(Event* event) {

}
string Node::Info() {
    return "Name " + string(this->GetClassName()) + " | Id " + string(this->id);
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
Vector2 Node::GetPosition() {
    auto x = this->rect.x;
    auto y = this->rect.y;
    return Vector2(x, y);
}
void Node::SetPosition(Vector2 pos) {
    this->rect.x = pos.x;
    this->rect.y = pos.y;
}
Vector2 Node::GetSize() {
    auto w = this->rect.w;
    auto h = this->rect.h;
    return Vector2(w, h);
}
void Node::SetSize(Vector2 size) {
    this->rect.w = size.x;
    this->rect.h = size.y;
}
Vector2 Node::GetAbsolutePosition() {
    Vector2 absPosition = this->GetPosition();
    Node* parent = this->parent;
    while (parent != nullptr)
    {
        Vector2 parentRelativePosition = parent->GetPosition();
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
    this->SetPosition(pos-absPosition);
}

