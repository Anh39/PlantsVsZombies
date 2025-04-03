#pragma once
#include "engine.h"
#include "mapTile.h"
#include <vector>
using namespace std;

class Map: public EventNode
{
public:
    void LoadMap(string filePath);
    void SaveMap(string filePath);
    Map();
    void LoadDefault();

    void Update(float delta) override;
    void SetSize(Vector2 size);
    void ProcessEvent(Event* event) override;
private:
    Vector2 renderSize;
    Vector2 mapSize;
    vector<vector<MapTile*>> tiles;
    Vector2 GetTileSize();
    MapTile* GetTileWithPosition(Vector2 position);
};