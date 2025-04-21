#include "wallnut.h"


Wallnut::Wallnut() {
    this->heathPoint = 1000;
    this->sunCost = 50;
    this->cardCooldown = 5;
    this->cooldown = 1;
    this->time = 0;
    float animationTime = 2;

    this->spriteRect1 = new SpriteRect();
    Texture* spriteTexture1 = new Texture("asset/plants/walnut/Walnut-sheet-1.png");
    this->spriteRect1->SetTexture(spriteTexture1, Vector2(8, 8), 58);
    this->spriteRect1->animationTime = animationTime;
    this->AddChildren(this->spriteRect1);

    this->spriteRect2 = new SpriteRect();
    Texture* spriteTexture2 = new Texture("asset/plants/walnut/Walnut-sheet-3.png");
    this->spriteRect2->SetTexture(spriteTexture2, Vector2(8, 7), 50);
    this->spriteRect2->animationTime = animationTime;
    this->AddChildren(this->spriteRect2);

    this->spriteRect3 = new SpriteRect();
    Texture* spriteTexture3 = new Texture("asset/plants/walnut/Walnut-sheet-4.png");
    this->spriteRect3->SetTexture(spriteTexture3, Vector2(8, 7), 50);
    this->spriteRect3->animationTime = animationTime;
    this->AddChildren(this->spriteRect3);

    this->spriteRect4 = new SpriteRect();
    Texture* spriteTexture4 = new Texture("asset/plants/walnut/Walnut-sheet-5.png");
    this->spriteRect4->SetTexture(spriteTexture4, Vector2(8, 7), 50);
    this->spriteRect4->animationTime = animationTime;
    this->AddChildren(this->spriteRect4);
}

Wallnut::~Wallnut() {

}

BasePlant* Wallnut::Create() {
    Wallnut* nut = new Wallnut();
    return nut;
}

Texture* Wallnut::GetIcon() {
    return new Texture("asset/plants/walnut/Walnut.png");
}

void Wallnut::SetSize(const Vector2& size) {
    BasePlant::SetSize(size);
    this->spriteRect1->size = size;
    this->spriteRect2->size = size;
    this->spriteRect3->size = size;
    this->spriteRect4->size = size;
}

Vector2 Wallnut::GetSize() {
    return this->size;
}
void Wallnut::HideAll() {
    this->spriteRect1->isVisible = false;
    this->spriteRect2->isVisible = false;
    this->spriteRect3->isVisible = false;
    this->spriteRect4->isVisible = false;
}
void Wallnut::Update(float delta) {
    BasePlant::Update(delta);
    if (this->heathPoint >= 750) {
        this->HideAll();
        this->spriteRect1->isVisible = true;
    }
    else if (this->heathPoint >= 500) {
        this->HideAll();
        this->spriteRect2->isVisible = true;
    }
    else if (this->heathPoint >= 250) {
        this->HideAll();
        this->spriteRect3->isVisible = true;
    }
    else {
        this->HideAll();
        this->spriteRect4->isVisible = true;
    }
}