#include "sunController.h"
#include <random>

SunController::SunController() {

    this->delay = 2;
    this->time = 0;
}

SunController::~SunController() {

}
float randomRange(float from, float to) {
    return std::rand() % int(from - to) + from;
}
void SunController::Update(float delta) {
    this->time += delta;
    if (this->time >= this->delay) {
        this->time = 0;
        float x = randomRange(100, 1920 - 100);
        float maxY = randomRange(100, 1080 - 100);
        SunDrop* sundrop = new SunDrop();
        sundrop->maxY = maxY;
        sundrop->size = Vector2(100, 100);
        sundrop->position = Vector2(x, 0);
        sundrop->velocity = Vector2(0, 100);
        sundrop->OnClicked = [this](SunDrop* src) {
            src->Collect(Vector2(30, 30), 1);
            SunCollectedEvent* event = new SunCollectedEvent(50);
            EventQueue::PushEvent(event);
        };
        this->AddChildren(sundrop);
    }
}