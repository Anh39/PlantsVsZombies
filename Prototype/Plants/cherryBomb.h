#pragma once
#include "basePlant.h"

class CherryBomb : public BasePlant {
public:
    float explodeDelay;    
    float currentTimer; 
    bool hasExploded;

    CherryBomb();
    ~CherryBomb();

    BasePlant* Copy() override;
    void Update(float delta) override;
};