#include "normalZombie.h"

NormalZombie::NormalZombie() {
    this->color = Color(255, 0, 0);
    this->collideFilter = 0x10;
}
NormalZombie::~NormalZombie() {

}
BaseZombie* NormalZombie::Copy() {
    return nullptr;
}

void NormalZombie::Update(float delta) {
    this->rect = this->rect - Vector2(10, 0) * delta;
}
