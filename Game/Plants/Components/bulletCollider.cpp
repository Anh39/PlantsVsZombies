#include "bulletCollider.h"
#include "../../Zombies/Components/zombieCollider.h"

BulletColliderBox::BulletColliderBox() {
    this->collideMask = CollideMask::Mask_Zombie;
    this->collideFilter = CollideMask::Mask_Bullet;
    this->visualBox->color = Color(0, 0, 255);
    this->AddChildren(this->visualBox);
}
BulletColliderBox::~BulletColliderBox() {};
void BulletColliderBox::OnCollide(CollideNode* node) {
    ZombieColliderBox* zombieHitbox = dynamic_cast<ZombieColliderBox*>(node);
    if (zombieHitbox) {
        BaseZombie* zombie = dynamic_cast<BaseZombie*>(zombieHitbox->parent);
        if (zombie && this->OnCollideWithZombie) {
            this->OnCollideWithZombie(zombie);
        }
    }
}
void BulletColliderBox::Update(float delta) {
    this->visualBox->size = this->size;
    this->visualBox->isVisible = KeyboardEvent::IsPressing(KeyboardType::F12);
}
