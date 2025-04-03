#include "collideNode.h"

CollideNode::CollideNode() {
    this->feature = NodeFeatureMask::BASIC_NODE | NodeFeatureMask::COLLIDE_NODE;
    this->Name = "CollideNode";
}
CollideNode::~CollideNode() {

}
void CollideNode::OnCollide(CollideNode* other) {

}
void CollideNode::OnCollided(CollideNode* other) {

}