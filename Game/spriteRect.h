#pragma once

#include "engine.h"

class SpriteRect: public RenderNode
{
public:
    SpriteRect();
    ~SpriteRect();

    void SetTexture(Texture* texture, Vector2 gridSize, int totalImages);
    void Update(float delta) override;
    void Draw(Renderer* renderer, Vector2 absolutePosition) override;
    void Step();
    void Reset();
    float animationTime;
private:
    float time;
    Texture* texture;
    Vector2 elementSize;
    int totalIndex;
    int currentIndex;
    int width;
    int height;
    Rect GetCurrentRect();
};