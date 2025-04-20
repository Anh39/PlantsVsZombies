#include "testZombie.h"

TestZombie::TestZombie() {
    this->speed = 100;
    this->displayBox = new ColorRect();
    this->displayBox->color = Color(255, 0, 0);
    this->displayBox->size = Vector2(150, 150);
    this->AddChildren(this->displayBox);
}

TestZombie::~TestZombie() {

}

void TestZombie::Update(float delta) {
    BaseZombie::Update(delta);
    this->position.x -= this->speed * delta;
}