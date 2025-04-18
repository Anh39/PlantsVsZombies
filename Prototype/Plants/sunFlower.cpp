#include "Sunflower.h"

Sunflower::Sunflower() : BasePlant() {
    this->Name = "Sunflower";
    this->color = Color(255, 255, 0); 
    this->size = Vector2(50, 50);   
    this->isActive = true;
}

Sunflower::~Sunflower() {
}

BasePlant* Sunflower::Copy() {
    Sunflower* newSunflower = new Sunflower();
    newSunflower->color = this->color;
    newSunflower->position = this->position;
    newSunflower->size = this->size;
    newSunflower->isActive = this->isActive;
    return newSunflower;
}

void Sunflower::Update(float delta) {
    if (!this->isActive) return;
}