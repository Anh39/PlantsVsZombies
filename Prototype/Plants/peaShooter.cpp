#include "peaShooter.h"

PeaBullet::PeaBullet() {
    this->color = Color(0, 255, 127);
    this->rect = Rect(0, 0, 10, 10);
    this->velocity = Vector2(50, 0);
    this->collideMask = 0x10;
}
PeaBullet::~PeaBullet() {

}
void PeaBullet::Update(float delta) {
    this->rect = this->rect + (this->velocity * delta);
}
void PeaBullet::OnCollide(Node* other) {
    other->Delete();
    this->Delete();
}


PeaShooter::PeaShooter() {
    this->color = Color(0, 255, 0);
    this->rect = Rect(0, 0, 50, 50);
    this->time = 0;
    this->delay = 1;
    this->isMoving = false;
}

PeaShooter::~PeaShooter() {

}

BasePlant* PeaShooter::Copy() {
    PeaShooter* newInstance = new PeaShooter();
    newInstance->color = this->color;
    newInstance->rect = this->rect;
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
        this->AddChildren(bullet);
    }
    // Rect rect =  this->rect;
    // rect.SetPosition(this->GetAbsolutePosition());
    // if (!this->isMoving && MouseEvent::JustPressed(MouseType::MouseLeft)) {
    //     if (rect.Contain(MouseEvent::Position())) {
    //         this->isMoving = true;
    //         this->startPosition = this->GetPosition();
    //         this->startMousePosition = MouseEvent::Position();
    //     }
    // }
    // if (this->isMoving) {
    //     if (MouseEvent::JustReleased(MouseType::MouseLeft)) {
    //         this->isMoving = false;
    //     }
    //     this->SetPosition(MouseEvent::Position() - this->startMousePosition + this->startPosition);
    // }
}
