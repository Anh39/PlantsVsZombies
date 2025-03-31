#pragma once
#include "engine.h"
#include "../Plants/basePlant.h"

class PlantCardDropEvent: public Event 
{
public:
    BasePlant* Plant;
    Vector2 AbsolutePosition;
};
