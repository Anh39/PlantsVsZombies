#pragma once
#include "baseZombie.h"

class BucketZombie : public BaseZombie {
public:
    BucketZombie();
    virtual ~BucketZombie();
    virtual BaseZombie* Copy() override;
};
