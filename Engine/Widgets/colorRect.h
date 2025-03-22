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
    void Draw(Renderer *renderer, Vector2F absolutePosition);
    // virtual void update(float delta);
    // virtual string GetClassName() override;

    const string GetClassName() { return "ColorRect"; }
};