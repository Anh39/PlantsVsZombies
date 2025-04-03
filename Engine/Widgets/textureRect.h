#pragma once

#include "../nodes.h"
#include "../graphic.h"

/// @class TextureRect
/// @brief Basic Node that render a Rectangle with image
class TextureRect: public RenderNode
{
public:
    /// @brief Texture of rect
    Texture* texture;

    TextureRect();
    ~TextureRect();
    void Draw(Renderer *renderer, Vector2 absolutePosition) override;
};