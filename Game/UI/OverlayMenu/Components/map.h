#pragma once

#include "engine.h"
#include "mapTile.h"
#include "../../../level.h"

class Map : public EventNode
{
public:
    Map(Vector2 size, Vector2 mapSize, std::vector<ZombieWave> zombieWaves);
    ~Map();

    void ProcessEvent(Event* event) override;
    void Update(float delta) override;
    bool PlacePlant(BasePlant* plant, const Vector2& position);
    bool ShovelPlant(const Vector2& position);
    void PlaceHologram(Texture* icon, const Vector2& position);
    void ClearHologram();

    Vector2 GetTileSize();

private:
    Vector2 size;
    Vector2 mapSize;
    Vector2 tileSize;
    float waveTime;
    ZombieWave currentWave;
    std::vector<ZombieWave> waves;

    MapTile* GetByPosition(const Vector2& position);
    std::vector<std::vector<MapTile*>> tileBoxs;
};