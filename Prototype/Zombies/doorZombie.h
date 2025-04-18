#pragma once
#include "baseZombie.h"

class DoorZombie : public BaseZombie {
public:
    DoorZombie();
    virtual ~DoorZombie();
    virtual BaseZombie* Copy() override;
};
