#pragma once
#include "engine.h"

using namespace std;

class BaseZombie: public ColorRect
{
public:
    BaseZombie();
    ~BaseZombie();
    virtual BaseZombie* Copy();
    const string GetClassName() override {return "BaseZombie";}
};