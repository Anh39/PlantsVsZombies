#include "zombieDetectorCollider.h"
#include "../../Plants/Components/plantCollider.h"

ZombieDetectorColliderBox::ZombieDetectorColliderBox() {
    this->collideMask = Mask_Plant;
    this->collideFilter = 0;
    this->visualBox->color = Color(0, 0, 0);
    this->AddChildren(this->visualBox);
}


ZombieDetectorColliderBox::~ZombieDetectorColliderBox() {

}

void ZombieDetectorColliderBox::Update(float delta) {
    this->visualBox->size = this->size;
    this->visualBox->isVisible = KeyboardEvent::IsPressing(KeyboardType::F3);
    this->hasPlant = false;
}


void ZombieDetectorColliderBox::OnCollide(CollideNode* node)   {
    PlantColliderBox* plantHitbox = dynamic_cast<PlantColliderBox*>(node);
    if (plantHitbox) {
        this->hasPlant = true;
        BasePlant* plant = dynamic_cast<BasePlant*>(node->parent);
        if (plant && this->OnCollidedWithPlant) {
            this->OnCollidedWithPlant(plant);
        }
    } 
}