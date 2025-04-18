#pragma once

#include "engine.h"
#include <functional>

class SunDrop: public RenderNode
{
public:
    std::function<void(SunDrop*)> OnClicked;
    float maxY;
    SunDrop();
    ~SunDrop();

    void Update(float delta) override;
    void Draw(Renderer* renderer, Vector2 absolutePosition) override;
    Vector2 velocity;

    void Collect(Vector2 destination, float time);
private:
    float disappearCooldown;
    float disappearTime;

    float middleDegree;
    float outerDegree;
    Vector2 collectDestination;
    float moveTime;
    bool isCollected;

    Texture* core;
    Texture* middle;
    Texture* outer;
};