#pragma once
#include "baseZombie.h"

class ConeZombie : public BaseZombie {
public:
    ConeZombie();
    virtual ~ConeZombie();
    virtual BaseZombie* Copy() override;
};
