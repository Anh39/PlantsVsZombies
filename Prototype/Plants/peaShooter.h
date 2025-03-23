#pragma once
#include "engine.h"

class PeaBullet: public ColorRect
{
public:
    Vector2 velocity;

    PeaBullet();
    ~PeaBullet();
    void Update(float delta) override;
    const string GetClassName() override {return "PeaBullet";}
};


class PeaShooter: public ColorRect
{
public:
    float time;
    float delay;

    PeaShooter();
    ~PeaShooter();

    void Update(float delta) override;
    const string GetClassName() override {return "PeaShooter";}

    bool isMoving;
    Vector2 startPosition;
    Vector2 startMousePosition;
};

