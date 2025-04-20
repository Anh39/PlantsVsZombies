#include "loseOverlay.h"
#include "../../../level.h"

LoseOverlay::LoseOverlay() {
    this->background = new TextureRect();
    this->background->texture = new Texture("asset/menu/ZombiesWon.jpg");
    this->AddChildren(this->background);
    this->background->isVisible = false;
    this->background->size = Vector2(1920, 1080);
    this->background->position = Vector2(0, 0);
}

LoseOverlay::~LoseOverlay() {

}

void LoseOverlay::Start() {
    this->background->isVisible = true;
}

void LoseOverlay::Update(float delta) {
    if (KeyboardEvent::JustPressed(KeyboardType::F8)) {
        this->Start();
    }
}

void LoseOverlay::ProcessEvent(Event* event) {
    LoseEvent* loseEvent = dynamic_cast<LoseEvent*>(event);
    if (loseEvent) {
        this->Start();
    }
}