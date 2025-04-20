#pragma once

#include "engine.h"

class PlantDetectorColliderBox: public CollideNode
{
public:
    bool hasZombie = false;
    PlantDetectorColliderBox();
    ~PlantDetectorColliderBox();
    void OnCollide(CollideNode* node) override;
    void Update(float delta) override;
private:
    ColorRect* visualBox = new ColorRect();
};