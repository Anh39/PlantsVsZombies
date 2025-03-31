#pragma once
#include "basePlant.h"

class PeaBullet: public ColorRect
{
public:
    Vector2 velocity;

    PeaBullet();
    ~PeaBullet();
    void Update(float delta) override;
    void OnCollide(Node* other) override;
    const string GetClassName() override {return "PeaBullet";}
};


class PeaShooter: public BasePlant
{
public:
    float time;
    float delay;

    PeaShooter();
    ~PeaShooter();

    void Update(float delta) override;
    const string GetClassName() override {return "PeaShooter";}
    BasePlant* Copy() override;


    bool isMoving;
    Vector2 startPosition;
    Vector2 startMousePosition;
};

