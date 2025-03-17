#pragma once

#include "../core.h"
#include "../dataTypes.h"
#include "../graphic.h"

class ColorRect: public Node 
{
public:
    Color color;

    ColorRect();
    void Draw(Renderer *renderer, Vector2F absolutePosition);
    // virtual void update(float delta);
};