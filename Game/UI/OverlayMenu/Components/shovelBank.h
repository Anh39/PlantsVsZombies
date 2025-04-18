#pragma once

#include "engine.h"
#include <functional>

class ShovelEvent: public Event 
{
public:
    Vector2 absolutePostion;

    ShovelEvent(Vector2 absolutePostion) {
        this->absolutePostion = absolutePostion;
    }
    ~ShovelEvent() {

    };
};

class ShovelBank: public Node
{
public:
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