#include "loseOverlay.h"
#include "../../../level.h"

LoseOverlay::LoseOverlay() {
    this->background = new TextureRect();
    this->background->texture = new Texture("asset/menu/ZombiesWon.jpg");
    this->AddChildren(this->background);
    this->background->isVisible = false;
    this->background->size = Vector2(1920, 1080);
    this->background->position = Vector2(0, 0);

    this->titleButton = new MenuButton();
    this->titleButton->SetColor(Color(0, 255, 0));
    this->titleButton->SetText("To title");
    this->titleButton->SetSize(Vector2(150, 75));
    this->titleButton->position = (Vector2(1920, 1080) - Vector2(150, 75))/2;
    this->titleButton->position.y = 900;
    this->titleButton->isVisible = false;
    this->AddChildren(this->titleButton);

    this->titleButton->OnClicked = [this]() {
        if(this->ToTitleFunction) {
            this->ToTitleFunction();
        }
    };
}

LoseOverlay::~LoseOverlay() {

}

void LoseOverlay::Start() {
    this->background->isVisible = true;
    this->titleButton->isVisible = true;
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