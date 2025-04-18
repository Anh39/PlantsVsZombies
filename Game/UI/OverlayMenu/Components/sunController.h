#pragma once

#include "engine.h"
#include "sunDrop.h"

class SunCollectedEvent: public Event
{
public:
    SunCollectedEvent(float amount) {
        this->amount = amount;
    };
    ~SunCollectedEvent() {};
    float amount;
};
class SunSpentEvent: public Event
{
public:
    SunSpentEvent(float amount) {
        this->amount = amount;
    };
    ~SunSpentEvent() {};
    float amount;
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