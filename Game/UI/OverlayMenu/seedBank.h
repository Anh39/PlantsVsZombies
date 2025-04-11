#pragma once

#include "engine.h"

class SeedBank: public Node
{
public:
    SeedBank();
    ~SeedBank();
    void SetSize(const Vector2& size);
private:
    TextureRect* background;
};