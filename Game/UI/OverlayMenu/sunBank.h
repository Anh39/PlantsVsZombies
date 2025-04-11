#pragma once

#include "engine.h"
#include "../textRect.h"

class SunBank: public Node
{
public:
    SunBank();
    ~SunBank();
    void SetSize(const Vector2& size);
    float Amount;
    void Update(float delta) override;
private:
    TextureRect* background;
    TextRect* counter;
};