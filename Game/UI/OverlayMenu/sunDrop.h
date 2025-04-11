#pragma once

#include "engine.h"
#include <functional>

class SunDrop: public RenderNode
{
public:
    std::function<void(SunDrop*)> OnClicked;
    SunDrop();
    ~SunDrop();

    void Update(float delta) override;
    void Draw(Renderer* renderer, Vector2 absolutePosition) override;
    Vector2 velocity;

    void Collect(Vector2 destination, float time);
private:
    float middleDegree;
    float outerDegree;
    Vector2 destination;
    float moveTime;
    bool isCollected;

    Texture* core;
    Texture* middle;
    Texture* outer;
};