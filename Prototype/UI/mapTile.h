#pragma once
#include "engine.h"
#include "../Plants/basePlant.h"

enum MapType 
{
    TILE_NONE,
    TILE_LAND,
    TILE_WATER,
    TILE_ROOF
};
enum GraphicMapType
{
    TILE_NONE_1,
    TILE_NONE_2,
    TILE_LAND_1,
    TILE_LAND_2,
    TILE_WATER_1,
    TILE_WATER_2,
    TILE_ROOF_1,
    TILE_ROOF_2,
};
class MapTile: public TextureRect
{
public:
    MapType GetType();
    Texture* GetTexture();

    MapTile(MapType type, Texture* texture);    
    ~MapTile();
    const string GetClassName() override {return "MapTile";}
    string Info() override;

    void SetPlant(BasePlant* plant);
private:
    MapType type;
};