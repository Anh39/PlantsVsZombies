#include "map.h"
#include "uiEvent.h"
#include <math.h>


Map::Map() {
    this->mapSize = Vector2(9, 5);
    this->tiles = vector<vector<MapTile*>>();
    for(int y=0; y<this->mapSize.y; y++) {
        vector<MapTile*> row;
        for(int x=0; x<this->mapSize.x; x++) {
            MapType type = TILE_LAND;
            if ((y*int(this->mapSize.x) + x) % 2 == 0) {
                Texture* texture = new Texture("images/red.png");
                MapTile* tile = new MapTile(type, texture);
                row.push_back(tile);
                this->AddChildren(tile);
            } else {
                Texture* texture = new Texture("images/blue.png");
                MapTile* tile = new MapTile(type, texture);
                row.push_back(tile);
                this->AddChildren(tile);
            }
        }
        this->tiles.push_back(row);
    }
    this->SetSize(Vector2(450, 250));
}
void Map::SetSize(Vector2 size) {
    this->rect.w = size.x;
    this->rect.h = size.y;
    Vector2 tileSize = this->GetTileSize();
    for(int y=0; y<this->mapSize.y; y++) {
        for(int x=0; x<this->mapSize.x; x++) {
            MapTile* tile = this->tiles[y][x];
            tile->SetSize(tileSize);
            Vector2 tilePosition = Vector2(x*tileSize.x, y*tileSize.y);
            tile->SetPosition(tilePosition);
        }
    }
}
Vector2 Map::GetTileSize() {
    return Vector2(this->rect.w/this->mapSize.x, this->rect.h/this->mapSize.y);
}
MapTile* Map::GetTileWithPosition(Vector2 position) {
    Vector2 tileSize = this->GetTileSize();
    Vector2 tilePosition = Vector2(position.x/tileSize.x, position.y/tileSize.y);
    int y = floor(tilePosition.y);
    int x = floor(tilePosition.x);
    if (x>=0 && x<this->mapSize.x && y>=0 && y<this->mapSize.y) {
        return this->tiles[y][x];
    } else {
        return nullptr;
    }
}
void Map::ProcessEvent(Event* event) {
    PlantCardDropEvent* dropEvent = dynamic_cast<PlantCardDropEvent*>(event);
    if (dropEvent) {
        Vector2 relativePosition = dropEvent->AbsolutePosition - this->GetPosition();
        MapTile* targetTile = this->GetTileWithPosition(relativePosition);
        if (targetTile != nullptr) {
            targetTile->SetPlant(dropEvent->Plant);
        } else {
            delete dropEvent->Plant;
        }
    }
}

void Map::SaveMap(string filePath) {
    
}

void Map::LoadMap(string filePath) {

}

