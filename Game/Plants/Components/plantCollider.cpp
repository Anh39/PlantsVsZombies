#include "plantCollider.h"


PlantColliderBox::PlantColliderBox() {
    this->collideMask = 0;
    this->collideFilter = CollideMask::Mask_Plant;
    this->visualBox->color = Color(0, 255, 0);
    this->AddChildren(this->visualBox);
}
PlantColliderBox::~PlantColliderBox() {};
void PlantColliderBox::Update(float delta) {
    this->visualBox->size = this->size;
    this->visualBox->isVisible = KeyboardEvent::IsPressing(KeyboardType::F10);
}