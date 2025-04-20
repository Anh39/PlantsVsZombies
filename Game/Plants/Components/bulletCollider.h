#pragma once

#include "engine.h"
#include <functional>
#include "../../Zombies/baseZombie.h"


class BaseZombie;

class BulletColliderBox: public CollideNode
{
public:
    std::function<void(BaseZombie*)> OnCollideWithZombie;
    BulletColliderBox();
    ~BulletColliderBox();
    void OnCollide(CollideNode* node) override;
    void Update(float delta) override;
private:
    ColorRect* visualBox = new ColorRect();
};