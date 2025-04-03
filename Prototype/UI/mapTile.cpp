#include "mapTile.h"

vector<pair<MapGraphicType, int>> MapTile::serializeCodeMapping = {
    {TILE_NONE_1, 1},
    {TILE_NONE_2, 2},
    {TILE_LAND_1, 3},
    {TILE_LAND_2, 4},
    {TILE_WATER_1, 5},
    {TILE_WATER_2, 6},
    {TILE_ROOF_1, 7},
    {TILE_ROOF_2, 8}
};
map<MapGraphicType, string> MapTile::texturePathMapping = {
    {TILE_NONE_1, ""},
    {TILE_NONE_2, ""},
    {TILE_LAND_1, "images/blue.png"},
    {TILE_LAND_2, "images/red.png"},
    {TILE_WATER_1, ""},
    {TILE_WATER_2, ""},
    {TILE_ROOF_1, ""},
    {TILE_ROOF_2, ""}
};

MapTile::MapTile(MapType type, MapGraphicType graphicType) {
    this->Name = "MapTile";
    this->type = type;
    this->graphicType = graphicType;
    Texture* texture = new Texture(texturePathMapping[this->graphicType]);
    this->texture = texture;
}
MapTile::~MapTile() {
}
string MapTile::Info() {
    return "Name " + string(this->Name) + " | Id " + string(this->id) + " | " + string(this->GetRect());
}
MapType MapTile::GetType() {
    return this->type;
}
MapGraphicType MapTile::GetGraphicType() {
    return this->graphicType;
}
Texture* MapTile::GetTexture() {
    return this->texture;
}
void MapTile::SetPlant(BasePlant* plant) {
    this->AddChildren(plant);
    plant->position = Vector2(0, 0);
}