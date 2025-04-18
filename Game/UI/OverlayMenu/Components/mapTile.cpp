#include "mapTile.h"

MapTile::MapTile() {
    this->displayBox = new ColorRect();
    this->displayBox->color = Color(255, 0, 0);
    this->AddChildren(this->displayBox);
    this->hologram = new TextureRect();
    this->AddChildren(this->hologram);
}
MapTile::~MapTile() {

}

void MapTile::SetSize(const Vector2& size) {
    this->displayBox->size = size;
    this->hologram->size = size;
    this->size = size;
}
