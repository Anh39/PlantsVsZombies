#include "CherryBomb.h"

CherryBomb::CherryBomb() : BasePlant() {

    this->Name = "CherryBomb";
    this->color = Color(255, 0, 0);   
    this->size = Vector2(60, 60);    
    this->isActive = true;

    this->explodeDelay = 3.0f;
    this->currentTimer = 0.0f;
    this->hasExploded = false;
}

CherryBomb::~CherryBomb() {
}

BasePlant* CherryBomb::Copy() {
    CherryBomb* newBomb = new CherryBomb();
    newBomb->color = this->color;
    newBomb->position = this->position;
    newBomb->size = this->size;
    newBomb->isActive = this->isActive;
    newBomb->explodeDelay = this->explodeDelay;
    newBomb->currentTimer = this->currentTimer;
    newBomb->hasExploded = this->hasExploded;
    return newBomb;
}

void CherryBomb::Update(float delta) {
    if (!this->isActive || hasExploded) return;

    currentTimer += delta;

    if (currentTimer >= explodeDelay) {
        hasExploded = true;
        this->color = Color(255, 165, 0);
        this->isActive = false;          
    }
}