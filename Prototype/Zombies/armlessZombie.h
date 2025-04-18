#pragma once
#include "baseZombie.h"

class ArmlessZombie : public BaseZombie {
public:
    ArmlessZombie();
    virtual ~ArmlessZombie();
    virtual BaseZombie* Copy() override;
};
