#pragma once

#include "engine.h"
#include <functional>

class ShovelBank: public Node
{
public:
    std::function<void(Vector2)> OnShove;
    ShovelBank();
    ~ShovelBank();

    void SetSize(const Vector2& size, const Vector2& padding);
    void Update(float delta) override;
private:
    TextureRect* background;
    TextureRect* shovel;

    Vector2 size;
    Vector2 padding;

    bool isMoving;
};