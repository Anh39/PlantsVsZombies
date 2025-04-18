#pragma once
#include "baseZombie.h"

class FlagZombie : public BaseZombie {
public:
    FlagZombie();
    virtual ~FlagZombie();
    virtual BaseZombie* Copy() override;
};
