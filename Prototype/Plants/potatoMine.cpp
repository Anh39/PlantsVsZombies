#include "PotatoMine.h"

PotatoMine::PotatoMine() : BasePlant() {
    this->Name = "PotatoMine";
    this->color = Color(139, 69, 19); 
    this->size = Vector2(40, 40); 
    this->isActive = true;

    this->armTime = 15.0f;
    this->currentArmTimer = 0.0f;
    this->isArmed = false;
}

PotatoMine::~PotatoMine() { 
}

BasePlant* PotatoMine::Copy() {
    PotatoMine* newMine = new PotatoMine();

    newMine->color = this->color;
    newMine->position = this->position;
    newMine->size = this->size;
    newMine->isActive = this->isActive;

    newMine->armTime = this->armTime;
    newMine->currentArmTimer = this->currentArmTimer;
    newMine->isArmed = this->isArmed;
    return newMine;
}

void PotatoMine::Update(float delta) {
    if (!this->isActive) return;


    if (!isArmed) {
        currentArmTimer += delta;
    
        if (currentArmTimer >= armTime * 0.8f) {
            this->color = Color(255, 0, 0);
        }
        if (currentArmTimer >= armTime) {
            isArmed = true;
            this->color = Color(255, 165, 0);
        }
    }
}
