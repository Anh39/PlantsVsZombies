#include "basePlant.h"

BasePlant::BasePlant() {
    this->hitbox = new PlantColliderBox();
    this->size = Vector2(0, 0);

    this->AddChildren(this->hitbox);
}
BasePlant::~BasePlant() {

}

BasePlant* BasePlant::Create() {
    return new BasePlant();
}

void BasePlant::SetSize(const Vector2& size) {
    this->size = size;
    this->hitbox->size = size;
}

Vector2 BasePlant::GetSize() {
    return Vector2(0, 0);
}

Texture* BasePlant::GetIcon() {
    return nullptr;
}

void BasePlant::Update(float delta) {
    if (this->heathPoint <= 0) {
        this->Delete();
    }
}