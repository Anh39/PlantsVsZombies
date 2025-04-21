#include "sunflower.h"
#include "../UI/OverlayMenu/Components/sunDrop.h"
#include "../UI/OverlayMenu/Components/sunController.h"

Sunflower::Sunflower() {
    this->sun = 50;
    this->sunCost = 100;
    this->cooldown = 5;
    this->time = 0;
    this->heathPoint = 100;

    this->spriteRect = new SpriteRect();
    Texture* spriteTexture = new Texture("asset/plants/sunflower/sunflower_sheet.png");
    this->spriteRect->SetTexture(spriteTexture, Vector2(8, 8), 60);
    this->spriteRect->animationTime = 2;
    this->AddChildren(this->spriteRect);
}
Sunflower::~Sunflower() {

}

Texture* Sunflower::GetIcon() {
    return new Texture("asset/plants/sunflower/Sunflower.png");
}

void Sunflower::SetSize(const Vector2& size) {
    BasePlant::SetSize(size);
    this->spriteRect->size = size;
}
Vector2 Sunflower::GetSize() {
    return this->size;
}
BasePlant* Sunflower::Create() {
    Sunflower* flower = new Sunflower();
    return flower;
}

void Sunflower::Update(float delta) {
    BasePlant::Update(delta);
    this->time += delta;
    if (this->time > this->cooldown) {
        this->time = 0;
        SunDrop* sundrop = new SunDrop();
        sundrop->position.y = this->position.y;
        sundrop->size = Vector2(100, 100);
        sundrop->OnClicked = [this](SunDrop* src) {
            src->Collect(Vector2(30, 30), 1);
            SunCollectedEvent* event = new SunCollectedEvent(50);
            EventQueue::PushEvent(event);
        };
        this->AddChildren(sundrop);
    }
}