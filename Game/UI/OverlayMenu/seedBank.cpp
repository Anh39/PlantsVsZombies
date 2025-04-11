#include "seedBank.h"

SeedBank::SeedBank() {
    this->background = new TextureRect();
    this->background->texture = new Texture("asset/menu/SeedBank_P.png");
    this->background->position = Vector2(0, 0);

    this->AddChildren(this->background);
}

SeedBank::~SeedBank() {

}

void SeedBank::SetSize(const Vector2& size) {
    this->background->size = size;
}