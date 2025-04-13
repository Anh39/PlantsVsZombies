#include "coneZombie.h"

ConeZombie::ConeZombie() {
    this->Name = "ConeZombie";
    this->colorRect->color = Color(255, 165, 0); // Màu cam (hình nón giao thông)
}

ConeZombie::~ConeZombie() {
}

BaseZombie* ConeZombie::Copy() {
    return new ConeZombie(*this);
}
