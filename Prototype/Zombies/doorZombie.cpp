#include "doorZombie.h"

DoorZombie::DoorZombie() {
    this->Name = "DoorZombie";
    this->colorRect->color = Color(139, 69, 19); // Màu nâu (gợi liên tưởng cái cửa)
}

DoorZombie::~DoorZombie() {
}

BaseZombie* DoorZombie::Copy() {
    return new DoorZombie(*this);
}
