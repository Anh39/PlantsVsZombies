#include "testZombie.h"

TestZombie::TestZombie() {
    this->speed = 100;
    this->displayBox = new ColorRect();
    this->displayBox->color = Color(255, 0, 0);
    this->displayBox->size = Vector2(150, 150);
    this->AddChildren(this->displayBox);

    this->spriteRect = new SpriteRect();
    this->spriteRect->SetTexture(
        new Texture("resources/images/Zombie/Armless/ArmlessWalk1.png"), 
        Vector2(8, 6), // 8 cột, 6 hàng
        46 // 46 ảnh
    );
    this->spriteRect->animationTime = 5; // chạy trong 5 giây
    this->spriteRect->size = Vector2(150, 150);
    this->AddChildren(this->spriteRect);
}

TestZombie::~TestZombie() {

}

void TestZombie::Update(float delta) {
    BaseZombie::Update(delta);
    this->position.x -= this->speed * delta;
}