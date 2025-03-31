#include "mapTile.h"

MapTile::MapTile(MapType type, Texture* texture) {
    this->type = type;
    this->texture = texture;
}
MapTile::~MapTile() {
    delete this->texture;
}
string MapTile::Info() {
    return "Name " + string(this->GetClassName()) + " | Id " + string(this->id) + " | " + string(this->rect);
}
MapType MapTile::GetType() {
    return this->type;
}
Texture* MapTile::GetTexture() {
    return this->texture;
}
void MapTile::SetPlant(BasePlant* plant) {
    this->AddChildren(plant);
    plant->SetPosition(Vector2(0, 0));
}