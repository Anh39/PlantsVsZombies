#pragma once

#include "engine.h"
#include "mapTile.h"
#include "../../../level.h"

class PlantContainer : public EventNode
{
public:
    PlantContainer(Vector2 size, Vector2 mapSize);
    ~PlantContainer();

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

    MapTile* GetByPosition(const Vector2& position);
    std::vector<std::vector<MapTile*>> tileBoxs;
};