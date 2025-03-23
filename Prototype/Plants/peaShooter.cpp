#include "peaShooter.h"

PeaBullet::PeaBullet() {
    this->color = Color(0, 255, 127);
    this->rect = Rect(0, 0, 10, 10);
    this->velocity = Vector2(50, 0);
}
PeaBullet::~PeaBullet() {

}
void PeaBullet::Update(float delta) {
    this->rect = this->rect + (this->velocity * delta);
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

void PeaShooter::Update(float delta) {
    this->time += delta;
    if (this->time >= this->delay) {
        this->time = 0;
        PeaBullet* bullet = new PeaBullet();
        this->AddChildren(bullet);
    }
    Rect rect =  this->rect;
    rect.SetPosition(this->GetAbsolutePosition());
    if (!this->isMoving && MouseEvent::JustPressed(MouseType::MouseLeft)) {
        if (rect.Contain(MouseEvent::Position())) {
            this->isMoving = true;
            this->startPosition = this->GetPosition();
            this->startMousePosition = MouseEvent::Position();
        }
    }
    if (this->isMoving) {
        if (MouseEvent::JustReleased(MouseType::MouseLeft)) {
            this->isMoving = false;
        }
        this->SetPosition(MouseEvent::Position() - this->startMousePosition + this->startPosition);
    }
}