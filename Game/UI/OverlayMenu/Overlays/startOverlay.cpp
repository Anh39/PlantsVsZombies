#include "startOverlay.h"

void SetSizeAndPosition(TextureRect* textureRect, Vector2 size) {
    textureRect->size = size;
    textureRect->position = (Vector2(1920, 1080) - size)/2;
}

StartOverlay::StartOverlay() {
    this->started = false;
    this->transitTime = 1;
    this->time = this->transitTime;
    this->startReady = new TextureRect();
    this->startReady->texture = new Texture("asset/menu/StartReady.png");
    this->startSet = new TextureRect();
    this->startSet->texture = new Texture("asset/menu/StartSet.png");
    this->startPlant = new TextureRect();
    this->startPlant->texture = new Texture("asset/menu/StartPlant.png");

    SetSizeAndPosition(this->startReady, Vector2(300, 200));
    SetSizeAndPosition(this->startSet, Vector2(300, 200));
    SetSizeAndPosition(this->startPlant, Vector2(300, 200));

    this->AddChildren(this->startReady);
    this->AddChildren(this->startSet);
    this->AddChildren(this->startPlant);
}


StartOverlay::~StartOverlay() {

}

void StartOverlay::Start() {
    this->startReady->isVisible = true;
    this->startSet->isVisible = false;
    this->startPlant->isVisible = false;
    this->started = true;
}

void StartOverlay::Update(float delta) {
    if (!this->started) return;;
    this->time -= delta;
    if (this->time < 0) {
        this->time = this->transitTime;
        if (this->startPlant->isVisible) {
            this->startPlant->isVisible = false;
            this->started = false;
        }
        else if (this->startSet->isVisible) {
            this->startSet->isVisible = false;
            this->startPlant->isVisible = true;
        }
        else {
            this->startReady->isVisible = false;;
            this->startSet->isVisible = true;
        }
    }
}