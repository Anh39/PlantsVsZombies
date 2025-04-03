#include "plantCard.h"
#include "uiEvent.h"

PlantCard::PlantCard() {
    this->target = nullptr;
    this->isMoving = false;
    this->Name = "PlantCard";
}
PlantCard::~PlantCard() {
    delete this->target;
}
void PlantCard::SetTargetSize(const Vector2& size) {
    if (this->target != nullptr) {
        this->target->size = size;
    }
}
void PlantCard::SetTarget(BasePlant* target) {
    if (this->target != nullptr) {
        this->RemoveChildren(target);
    }
    this->AddChildren(target);
    this->target = target;
}
BasePlant* PlantCard::CreateTarget() {
    return this->target->Copy();
}

void PlantCard::Update(float delta) {
    if (this->target == nullptr) return;
    Rect rect =  this->target->GetRect();
    rect.SetPosition(this->GetAbsolutePosition());
    if (!this->isMoving && MouseEvent::JustPressed(MouseType::MouseLeft)) {
        if (rect.Contain(MouseEvent::Position())) {
            this->isMoving = true;
            this->startPosition = this->position;
            this->startMousePosition = MouseEvent::Position();
        }
        this->instanceTarget = this->target->Copy();
        this->AddChildren(this->instanceTarget);
    }
    if (this->isMoving) {
        this->instanceTarget->position = MouseEvent::Position() - this->startMousePosition + this->startPosition;
        if (MouseEvent::JustReleased(MouseType::MouseLeft)) {
            this->isMoving = false;
            PlantCardDropEvent* event = new PlantCardDropEvent();
            event->Plant = this->instanceTarget;
            event->AbsolutePosition = this->instanceTarget->GetAbsolutePosition();
            EventQueue::PushEvent(event);
            this->RemoveChildren(this->instanceTarget);
            this->instanceTarget = nullptr;
        }
    }
}