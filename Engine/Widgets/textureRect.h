#pragma once

#include "../core.h"
#include "../graphic.h"

/// @class TextureRect
/// @brief Basic Node that render a Rectangle with image
class TextureRect: public Node 
{
public:
    /// @brief Texture of rect
    Texture* texture;

    TextureRect();
    ~TextureRect();
    void Draw(Renderer *renderer, Vector2 absolutePosition);
    // virtual void update(float delta);
    const string GetClassName() { return "TextureRect"; }
};