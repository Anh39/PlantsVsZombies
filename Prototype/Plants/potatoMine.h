#pragma once
#include "basePlant.h"

class PotatoMine : public BasePlant {
public:
    float armTime;          
    float currentArmTimer;  
    bool isArmed;           

    PotatoMine();
    ~PotatoMine();

    BasePlant* Copy() override;
    void Update(float delta) override;
};