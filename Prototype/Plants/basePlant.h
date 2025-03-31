#pragma once
#include "engine.h"

using namespace std;

class BasePlant: public ColorRect
{
public:
    BasePlant();
    ~BasePlant();
    bool isActive;

    virtual BasePlant* Copy();
    void Draw(Renderer* renderer, Vector2 absolutePosition);
    const string GetClassName() override {return "BasePlant";}
    string Info() override;
};