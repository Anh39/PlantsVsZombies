#pragma once
#include "engine.h"

class ProgressRect: public TextureRect
{
public:
    ProgressRect();
    ~ProgressRect();
    void Progress(float percent);
    void Draw(Renderer* renderer, Vector2 absolutePosition) override;
private:
    float percent;
};