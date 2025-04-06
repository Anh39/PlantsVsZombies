#pragma once
#include "engine.h"

class LoadGrass: public TextureRect
{
public:
    LoadGrass();
    ~LoadGrass();
    void Progress(float percent);
    void Draw(Renderer* renderer, Vector2 absolutePosition) override;
private:
    float percent;
};