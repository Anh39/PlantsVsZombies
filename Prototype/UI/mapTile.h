#pragma once
#include "engine.h"
#include "../Plants/basePlant.h"
#include <map>

enum MapType 
{
    TILE_NONE,
    TILE_LAND,
    TILE_WATER,
    TILE_ROOF
};
enum MapGraphicType
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
    static vector<pair<MapGraphicType, int>> serializeCodeMapping;
    static map<MapGraphicType, string> texturePathMapping;

    MapType GetType();
    MapGraphicType GetGraphicType();
    Texture* GetTexture();

    MapTile(MapType type, MapGraphicType graphicType);
    ~MapTile();
    string Info() override;

    void SetPlant(BasePlant* plant);
private:
    MapType type;
    MapGraphicType graphicType;
};