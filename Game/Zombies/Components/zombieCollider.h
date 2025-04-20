#pragma once

#include "engine.h"

class ZombieColliderBox: public CollideNode
{
public:
    ZombieColliderBox();
    ~ZombieColliderBox();
    void Update(float delta) override;
private:
    ColorRect* visualBox = new ColorRect();
};