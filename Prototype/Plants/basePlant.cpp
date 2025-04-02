#include "basePlant.h"

BasePlant::BasePlant() {
    this->isActive = true;
}
BasePlant::~BasePlant() {
}

BasePlant* BasePlant::Copy() {
    return nullptr;
}
void BasePlant::Draw(Renderer* renderer, Vector2 absolutePosition) {
    if (!this->isActive) return;
    ColorRect::Draw(renderer, absolutePosition);
}

string BasePlant::Info() {
    return "Name " + string(this->GetClassName()) + " | Id " + string(this->id) + " | " + string(this->rect);
}