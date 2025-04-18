#pragma once
#include "basePlant.h"

class Sunflower : public BasePlant {
public:
    Sunflower();
    ~Sunflower();

    BasePlant* Copy() override;
    void Update(float delta) override;

    float productionTimer = 0.0f;
};