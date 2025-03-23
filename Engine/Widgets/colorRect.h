#pragma once

#include "../core.h"
#include "../dataTypes.h"
#include "../graphic.h"

class ColorRect: public Node 
{
public:
    const char* className = "ColorRect";

    Color color;

    ColorRect();
    void Draw(Renderer *renderer, Vector2 absolutePosition);

    const string GetClassName() { return "ColorRect"; }
};