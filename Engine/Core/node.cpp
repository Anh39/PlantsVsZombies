#include "node.h"
#include <random>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

Node::Node() {
    this->id = GenerateId();
    this->rect = Rect();
    this->children = vector<Node*>();
};
Node::~Node() {

}
void Node::Delete() {
    this->isDeleted = true;
    for (auto child : this->children)
    {
        child->Delete();
    }
}
void Node::Draw(Renderer* renderer, Vector2F absolutePosition) {

}
void Node::Update(float delta) {

}
void Node::OnCollide(Node* other) {

}
void Node::OnCollided(Node* other) {
    
}
string Node::Info() {
    return "Name " + string(this->GetClassName()) + " | Id " + string(this->id) + "\n";
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
Vector2F Node::GetPosition() {
    auto x = this->rect.x;
    auto y = this->rect.y;
    return Vector2F(x, y);
}
void Node::SetPosition(Vector2F pos) {
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
Vector2F Node::GetAbsolutePosition() {
    Vector2F absPosition = this->GetPosition();
    Node* parent = this->parent;
    while (parent != nullptr)
    {
        Vector2F parentRelativePosition = parent->GetPosition();
        absPosition.x += parentRelativePosition.x;
        absPosition.y += parentRelativePosition.y;
        parent = parent->parent;
        // parent = nullptr;
        // break;
    }
    return absPosition;
}
void Node::SetAbsolutePosition(Vector2F pos) {
    Vector2F absPosition = this->GetAbsolutePosition();
    this->SetPosition(pos-absPosition);
}

