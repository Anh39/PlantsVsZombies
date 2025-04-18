#include "shovelBank.h"

ShovelBank::ShovelBank() {
    this->isMoving = false;
    this->size = Vector2();
    this->padding = Vector2();

    this->background = new TextureRect();
    this->background->texture = new Texture("asset/menu/ShovelBank.png");
    this->background->position = Vector2(0, 0);

    this->shovel = new TextureRect();
    this->shovel->texture = new Texture("asset/menu/Shovel_hi_res.png");

    this->AddChildren(this->background);
    this->AddChildren(this->shovel);
}

ShovelBank::~ShovelBank() {

}

void ShovelBank::SetSize(const Vector2& size, const Vector2& padding) {
    this->size = size;
    this->padding = padding;
    this->background->size = size;
    this->shovel->position = padding;
    this->shovel->size = size - padding*2;
}

void ShovelBank::Update(float delta) {
    Rect rect = this->background->GetRect();
    Vector2 absPosition = this->GetAbsolutePosition();
    rect.SetPosition(absPosition);
    if (MouseEvent::JustPressed(MouseType::MouseLeft) && rect.Contain(MouseEvent::Position())) {
        this->isMoving = true;
    }
    if (MouseEvent::JustReleased(MouseType::MouseLeft)) {
        this->isMoving = false;
        if (this->OnShove) {
            this->OnShove(MouseEvent::Position());
        }
        this->shovel->position = this->padding;
    }
    if (this->isMoving) {
        this->shovel->position = MouseEvent::Position() - absPosition - this->shovel->size/2;
    }
}