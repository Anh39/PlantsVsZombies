#pragma once

#include "engine.h"
#include "Components/include.h"
class ZombieDetectorColliderBox;
class ZombieDieEvent: public Event
{
public:
    ZombieDieEvent() {};
    ~ZombieDieEvent() {};
};
class BaseZombie: public Node
{
public:
    float heathPoint = 1;
    float damage = 1;
    float speed = 100;
    float cooldown = 1;
    float range = 1; // n tiles ahead
    float time = 0;

    BaseZombie();
    ~BaseZombie();
    
    void Update(float delta) override;
    virtual void SetSize(const Vector2& size);
    virtual Vector2 GetSize();
protected:
    Vector2 size;
    ZombieDetectorColliderBox* detectorBox;
    ZombieColliderBox* hitbox;
};