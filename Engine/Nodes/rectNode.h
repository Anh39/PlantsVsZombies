#pragma once

#include "../core.h"

/// @class RectNode
/// @brief Node that have size, base class for some other nodes
class RectNode: public Node
{
public:
    Vector2 size;

    RectNode();
    ~RectNode();
    Rect GetRect();
    void SetRect(const Rect& rect);
};