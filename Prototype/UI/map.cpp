#include "map.h"
#include "uiEvent.h"
#include <math.h>
#include <fstream>

using namespace std;

Map::Map() {
    this->mapSize = Vector2(9, 5);
    this->tiles = vector<vector<MapTile*>>();
    this->Name = "Map";
}
void Map::LoadDefault() {
    for(int y=0; y<this->mapSize.y; y++) {
        vector<MapTile*> row;
        for(int x=0; x<this->mapSize.x; x++) {
            MapType type = TILE_LAND;
            if ((y*int(this->mapSize.x) + x) % 2 == 0) {
                MapTile* tile = new MapTile(type, TILE_LAND_1);
                row.push_back(tile);
                this->AddChildren(tile);
            } else {
                MapTile* tile = new MapTile(type, TILE_LAND_2);
                row.push_back(tile);
                this->AddChildren(tile);
            }
        }
        this->tiles.push_back(row);
    }
    this->SetSize(this->renderSize);
}
void Map::SetSize(Vector2 size) {
    this->renderSize = size;
    Vector2 tileSize = this->GetTileSize();
    for(int y=0; y<this->mapSize.y; y++) {
        for(int x=0; x<this->mapSize.x; x++) {
            MapTile* tile = this->tiles[y][x];
            tile->size = tileSize;
            Vector2 tilePosition = Vector2(x*tileSize.x, y*tileSize.y);
            tile->position = tilePosition;
        }
    }
}
Vector2 Map::GetTileSize() {
    return Vector2(this->renderSize.x/this->mapSize.x, this->renderSize.y/this->mapSize.y);
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
        Vector2 relativePosition = dropEvent->AbsolutePosition - this->position;
        MapTile* targetTile = this->GetTileWithPosition(relativePosition);
        if (targetTile != nullptr) {
            targetTile->SetPlant(dropEvent->Plant);
        } else {
            delete dropEvent->Plant;
        }
    }
}
void Map::Update(float delta) {
    if (KeyboardEvent::JustPressed(KeyboardType::F3)) {
        this->SaveMap("map.txt");
    }
}
void Map::SaveMap(string filePath) {
    string data = "";
    data += to_string(int(this->mapSize.x)) + " " + to_string(int(this->mapSize.y))+"\n";
    ofstream file(filePath);
    for(int y=0; y<this->mapSize.y; y++) {
        string row = "";
        for(int x=0; x<this->mapSize.x; x++) {
            int mapCode= -1;
            MapGraphicType graphicType = this->tiles[y][x]->GetGraphicType();
            for (auto &pair : MapTile::serializeCodeMapping)
            {
                if (pair.first == graphicType) {
                    mapCode = pair.second;
                    break;
                }
            }
            row += to_string(mapCode) + " ";
        }
        data += row + "\n";
    }
    if (file.is_open()) {
        file << data;
        file.close();
        cout << "Map write completed" << endl;
    } else {
        throw runtime_error("Failed to write map to " + filePath);
    }
}   

void Map::LoadMap(string filePath) {
    ifstream file(filePath);
    if (file.is_open()) {
        int width, height;
        file >> width >> height;
        this->mapSize = Vector2(width, height);
        for(int y=0; y<height; y++) {
            vector<MapTile*> row;
            for(int x=0; x<width; x++) {
                int mapCode;
                file >> mapCode;
                MapType type = TILE_LAND;
                MapGraphicType graphicType = TILE_NONE_1;
                for (auto &pair : MapTile::serializeCodeMapping)
                {
                    if (pair.second == mapCode) {
                        graphicType = pair.first;
                        break;
                    }
                }
                MapTile* tile = new MapTile(type, graphicType);
                row.push_back(tile);
                this->AddChildren(tile);

            }
            this->tiles.push_back(row);
        }
        file.close();
    } else {
        throw runtime_error("Failed to read map from " + filePath);
    }
}

