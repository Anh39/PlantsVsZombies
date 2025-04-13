#include "armlessZombie.h"

ArmlessZombie::ArmlessZombie() {
    this->Name = "ArmlessZombie";

    this->colorRect = new ColorRect();
    this->colorRect->color = Color(255, 0, 0); 
    this->AddChildren(this->colorRect);

    this->collider = new CollideNode();
    this->collider->collideFilter = CollideLayer1;
    this->AddChildren(this->collider);

}

ArmlessZombie::~ArmlessZombie() {
  

void ArmlessZombie::SetSize(const Vector2& size) {
  
    this->colorRect->size = size;
    this->collider->size = size;
}

ArmlessZombie* ArmlessZombie::Copy() {
    
    ArmlessZombie* newArmlessZombie = new ArmlessZombie();
    newArmlessZombie->SetSize(this->colorRect->size);  // Sao chép kích thước
    return newArmlessZombie;
}

void ArmlessZombie::Update(float delta) {

  
    this->position += Vector2(-10, 0) * delta;
}
