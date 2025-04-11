#pragma once

#include "engine.h"
#include "sunDrop.h"

class SunCollectedEvent: public Event
{
public:
    SunCollectedEvent() {};
    ~SunCollectedEvent() {};
    float Amount;
};


class SunController: public Node
{
public:
    SunController();
    ~SunController();

    void Update(float delta) override;
    float delay;
    float time;
};