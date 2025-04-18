#pragma once

#include "engine.h"

class StartOverlay: public Node
{
public:
    StartOverlay();
    ~StartOverlay();

    void Update(float delta) override;

    void Start();
private:
    TextureRect* startReady;
    TextureRect* startSet;
    TextureRect* startPlant;

    float time;
    float transitTime;
    float started;
};