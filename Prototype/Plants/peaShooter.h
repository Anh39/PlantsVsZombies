#pragma once
#include "basePlant.h"

class PeaShooter: public BasePlant
{
public:
    float time;
    float delay;

    PeaShooter();
    ~PeaShooter();

    void Update(float delta) override;
    BasePlant* Copy() override;


    bool isMoving;
    Vector2 startPosition;
    Vector2 startMousePosition;
};

