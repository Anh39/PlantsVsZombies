#include "flagZombie.h"

FlagZombie::FlagZombie() {
    this->Name = "FlagZombie";
    this->colorRect->color = Color(255, 0, 255); // Màu tím
}

FlagZombie::~FlagZombie() {
}

BaseZombie* FlagZombie::Copy() {
    return new FlagZombie(*this);
}
