#include "level.h"
using namespace std;


Level::Level() {
    this->plants = vector<BasePlant*>();
    this->zombieWaves = vector<ZombieWave>();
}

Level::~Level() {

}

BaseZombie::BaseZombie() {
    this->speed = 0;
}

BaseZombie::~BaseZombie() {
    ZombieDieEvent* event = new ZombieDieEvent();
    EventQueue::PushEvent(event);
}
void BaseZombie::SetSize(const Vector2& size) {

}
void BaseZombie::Update(float delta) {
    if (this->GetAbsolutePosition().x <= - this->GetSize().x) {
        LoseEvent* event = new LoseEvent();
        EventQueue::PushEvent(event);
    }
}
Vector2 BaseZombie::GetSize() {
    return Vector2(0, 0);
}

BasePlant::BasePlant() {
    this->sunCost = 0;
    this->cardCooldown = 10;
    this->heathPoint = 1;
    this->cooldown = 1;
    this->time = 0;
}
BasePlant::~BasePlant() {

}

BasePlant* BasePlant::Create() {
    return new BasePlant();
}

void BasePlant::SetSize(const Vector2& size) {

}

Vector2 BasePlant::GetSize() {
    return Vector2(0, 0);
}

Texture* BasePlant::GetIcon() {
    return nullptr;
}