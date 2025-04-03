#pragma once

#include "rectNode.h"

/// @class RenderNode
/// @brief Node that display graphic to screen
class RenderNode: public RectNode
{
public:
    RenderNode();
    ~RenderNode();

    /// @brief Draw function to show graphic.
    virtual void Draw(Renderer* renderer, Vector2 absolutePosition);
};