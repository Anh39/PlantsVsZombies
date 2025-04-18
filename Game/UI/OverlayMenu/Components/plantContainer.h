#pragma once

#include "engine.h"

class PlantContainer : public EventNode
{
public:
    PlantContainer();
    ~PlantContainer();

    void ProcessEvent(Event* event) override;
};