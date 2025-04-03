#pragma once

#include "../nodes.h"
#include "../dataTypes.h"
#include "../graphic.h"

/// @class ColorRect
/// @brief Basic Node that render a Rectangle with color
class ColorRect: public RenderNode
{
public:
    /// @brief Color of rect
    Color color;
    ColorRect();
    void Draw(Renderer *renderer, Vector2 absolutePosition) override;
};