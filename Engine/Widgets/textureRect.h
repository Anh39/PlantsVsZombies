#pragma once

#include "../core.h"
#include "../graphic.h"

class TextureRect: public Node 
{
public:
    Texture* texture;

    TextureRect();
    void Draw(Renderer *renderer, Vector2F absolutePosition);
    // virtual void update(float delta);
};