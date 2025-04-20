#pragma once

#include "engine.h"
#include "../../Plants/basePlant.h"
#include <functional>

class BasePlant;

class ZombieDetectorColliderBox: public CollideNode
{
public:
    std::function<void(BasePlant*)> OnCollidedWithPlant;
    bool hasPlant = false;
    ZombieDetectorColliderBox();
    ~ZombieDetectorColliderBox();
    void OnCollide(CollideNode* node) override;
    void Update(float delta) override;
private:
    ColorRect* visualBox = new ColorRect();
};