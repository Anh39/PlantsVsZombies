#include "zombieCollider.h"

ZombieColliderBox::ZombieColliderBox()  {
    this->collideMask = CollideMask::Mask_Plant;
    this->collideFilter = CollideMask::Mask_Zombie;
    this->visualBox->color = Color(255, 0, 0);
    this->AddChildren(this->visualBox);
};

ZombieColliderBox::~ZombieColliderBox() {

}

void ZombieColliderBox::Update(float delta)  {
    this->visualBox->size = this->size;
    this->visualBox->isVisible = KeyboardEvent::IsPressing(KeyboardType::F11);
}