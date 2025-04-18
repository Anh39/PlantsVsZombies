#pragma once

#include "engine.h"

class MapTile: public CollideNode
{
public:
    MapTile();
    ~MapTile();

    ColorRect* displayBox;
    TextureRect* hologram;

    void SetSize(const Vector2& size);
private:
};