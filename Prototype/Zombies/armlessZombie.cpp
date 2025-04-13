#include "armlessZombie.h"

ArmlessZombie::ArmlessZombie() {
    this->Name = "ArmlessZombie";
    this->colorRect->color = Color(0, 255, 0); // Màu xanh lá
}

ArmlessZombie::~ArmlessZombie() {
}

BaseZombie* ArmlessZombie::Copy() {
    return new ArmlessZombie(*this);
}
