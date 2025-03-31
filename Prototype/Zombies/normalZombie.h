#pragma once
#include "engine.h"
#include "baseZombie.h"

using namespace std;

class NormalZombie: public BaseZombie
{
public:
    NormalZombie();
    ~NormalZombie();

    void Update(float delta) override;

    virtual BaseZombie* Copy();
    const string GetClassName() override {return "NormalZombie";}
};