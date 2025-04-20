#include "plantDetectorCollider.h"
#include "../../Zombies/Components/zombieCollider.h"


PlantDetectorColliderBox::PlantDetectorColliderBox() {
    this->collideMask = Mask_Zombie;
    this->collideFilter = 0;
    this->visualBox->color = Color(255, 255, 255);
    this->AddChildren(this->visualBox);
}
PlantDetectorColliderBox::~PlantDetectorColliderBox() {

};
void PlantDetectorColliderBox::OnCollide(CollideNode* node) {
    ZombieColliderBox* zombieHitbox = dynamic_cast<ZombieColliderBox*>(node);
    if (zombieHitbox) {
        this->hasZombie = true;
    }
}
void PlantDetectorColliderBox::Update(float delta) {
    this->visualBox->size = this->size;
    this->visualBox->isVisible = KeyboardEvent::IsPressing(KeyboardType::F4);
    this->hasZombie = false;

}
