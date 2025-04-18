#pragma once

#include "engine.h"
#include <functional>

class Trophy: public RenderNode
{
public:
    std::function<void()> OnEnd;
    Trophy();
    ~Trophy();

    void Draw(Renderer* renderer, Vector2 absolutePosition) override;
    void Update(float delta) override;
    void Start();
    float scale;
private:
    bool started;
    float scaleSpeed = 0.2;
    float rotationSpeed;
    float rayDegree1;
    float rayDegree2;
    Texture* trophyTexture;
    Texture* glowTexture;
    Texture* rayTexture1;
    Texture* rayTexture2;
};