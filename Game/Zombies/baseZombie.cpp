#include "baseZombie.h"
#include "../level.h"

BaseZombie::BaseZombie() {
    this->speed = 0;

    this->detectorBox = new ZombieDetectorColliderBox();
    this->AddChildren(this->detectorBox);

    this->hitbox = new ZombieColliderBox();
    this->AddChildren(this->hitbox);
}

BaseZombie::~BaseZombie() {
}

void BaseZombie::SetSize(const Vector2& size) {
    this->size = size;
    this->hitbox->size = Vector2(size.x * 0.5, size.y);
    this->hitbox->position.x = size.x * 0.5;
    this->detectorBox->size = Vector2(size.x * this->range * 0.5, size.y);
    this->detectorBox->position.x = size.x * 0.5;
}
Vector2 BaseZombie::GetSize() {
    return this->size;
}

void BaseZombie::Update(float delta) {
    if (this->GetAbsolutePosition().x <= - this->GetSize().x) {
        LoseEvent* event = new LoseEvent();
        EventQueue::PushEvent(event);
    }
    if (this->heathPoint <= 0){
        this->Delete();
        ZombieDieEvent* event = new ZombieDieEvent();
        EventQueue::PushEvent(event);
        std::cout << "DIED" << std::endl;
    }
}