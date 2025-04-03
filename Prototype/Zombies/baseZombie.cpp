#include "baseZombie.h"

BaseZombie::BaseZombie() {
    this->Name = "BaseZombie";

    this->colorRect = new ColorRect();
    this->colorRect->color = Color(255, 0, 0);
    this->AddChildren(this->colorRect);

    this->collider = new CollideNode();
    this->collider->collideFilter = CollideLayer1;
    this->AddChildren(this->collider);
}
BaseZombie::~BaseZombie() {

}
void BaseZombie::SetSize(const Vector2& size) {
    this->colorRect->size = size;
    this->collider->size = size;
}
BaseZombie* BaseZombie::Copy() {
    return nullptr;
}

