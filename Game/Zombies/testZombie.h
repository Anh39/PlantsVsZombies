#pragma once

#include "engine.h"
#include "../level.h"

class TestZombie: public BaseZombie
{
public:
    TestZombie();
    ~TestZombie();

    void Update(float delta) override;
private:
    ColorRect* displayBox;
};