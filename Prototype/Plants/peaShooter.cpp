#include "peaShooter.h"
#include "peaBullet.h"

PeaShooter::PeaShooter() {
    this->color = Color(0, 255, 0);
    this->size = Vector2(50, 50);
    this->time = 0;
    this->delay = 1;
    this->isMoving = false;

    this->Name = "PeaShooter";
}

PeaShooter::~PeaShooter() {

}

BasePlant* PeaShooter::Copy() {
    PeaShooter* newInstance = new PeaShooter();
    newInstance->color = this->color;
    newInstance->position = this->position;
    newInstance->size = this->size;
    newInstance->time = this->time;
    newInstance->delay = this->delay;
    newInstance->isMoving = this->isMoving;
    newInstance->isActive = this->isActive;
    return newInstance;
}

void PeaShooter::Update(float delta) {
    if (!this->isActive) return;
    this->time += delta;
    if (this->time >= this->delay) {
        this->time = 0;
        PeaBullet* bullet = new PeaBullet();
        bullet->SetSize(Vector2(10, 10));
        this->AddChildren(bullet);
    }
}
