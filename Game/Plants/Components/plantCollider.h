#pragma once

#include "engine.h"

class PlantColliderBox: public CollideNode
{
public:
    PlantColliderBox();
    ~PlantColliderBox();
    void Update(float delta) override;
private:
    ColorRect* visualBox = new ColorRect();
};