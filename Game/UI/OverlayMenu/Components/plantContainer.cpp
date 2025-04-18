#include "plantContainer.h"
#include "plantCard.h"
#include "shovelBank.h"

using namespace std;

PlantContainer::PlantContainer(Vector2 size, Vector2 mapSize) {
    this->Name = "PlantContainer";
    this->size = size;
    this->mapSize = mapSize;
    this->tileSize = Vector2(this->size.x / this->mapSize.x, this->size.y / this->mapSize.y);
    this->tileBoxs = vector<vector<MapTile*>>(this->mapSize.y, vector<MapTile*>(this->mapSize.x));
    for(int y=0; y<mapSize.y; y++) {
        for(int x=0; x<mapSize.x; x++) {
            MapTile* newTile = new MapTile();
            newTile->SetSize(this->tileSize);
            if (int(y*mapSize.y + x) % 2 == 0) {
                newTile->displayBox->color = Color(255, 0, 0, 127);
            } else {
                newTile->displayBox->color = Color(0, 0, 255, 127);
            }
            newTile->displayBox->isVisible = false;
            newTile->position = Vector2(tileSize.x*x, tileSize.y*y);
            this->tileBoxs[y][x] = newTile;
            this->AddChildren(newTile);
        }
    }
}

PlantContainer::~PlantContainer() {

}

void PlantContainer::ProcessEvent(Event* event) {
    PlantCardHoverEvent* plantCardHoverEvent = dynamic_cast<PlantCardHoverEvent*>(event);
    if (plantCardHoverEvent) {
        Texture* icon = plantCardHoverEvent->icon;
        Vector2 position = plantCardHoverEvent->absolutePosition - this->GetAbsolutePosition();
        this->ClearHologram();
        this->PlaceHologram(icon, position);
    }
    PlantCardPlacedEvent* plantCardPlacedEvent = dynamic_cast<PlantCardPlacedEvent*>(event);
    if (plantCardPlacedEvent) {
        BasePlant* plant = plantCardPlacedEvent->plant;
        Vector2 position = plantCardPlacedEvent->absolutePosition - this->GetAbsolutePosition();
        bool success = this->PlacePlant(plant, position);
        if (success) {
            plantCardPlacedEvent->handled = true;
            if (plantCardPlacedEvent->onSuccess) {
                plantCardPlacedEvent->onSuccess();
            }
            this->ClearHologram();
        }
    }
    ShovelEvent* shovelEvent = dynamic_cast<ShovelEvent*>(event);
    if (shovelEvent) {
        Vector2 position = shovelEvent->absolutePostion - this->GetAbsolutePosition();
        this->ShovelPlant(position);
    }
}

Vector2 PlantContainer::GetTileSize() {
    return this->tileSize;
}

void PlantContainer::Update(float delta) {
    bool boxVisible = false;
    if (KeyboardEvent::IsPressing(KeyboardType::F6)) {
        boxVisible = true;
    }
    for(int y=0; y<mapSize.y; y++) {
        for(int x=0; x<mapSize.x; x++) {
            MapTile* mapTile = this->tileBoxs[y][x];
            mapTile->displayBox->isVisible = boxVisible;
        }
    }
}

MapTile* PlantContainer::GetByPosition(const Vector2& position) {
    int x = position.x / this->tileSize.x;
    int y = position.y / this->tileSize.y;
    if (x < 0 || x > this->mapSize.x - 1 || y < 0 || y > this->mapSize.y - 1) {
        return nullptr;
    } 
    else {
        return this->tileBoxs[y][x];
    }
}

bool PlantContainer::PlacePlant(BasePlant* plant, const Vector2& position) {
    MapTile* tile = this->GetByPosition(position);
    if (tile != nullptr && tile->children.size() == 2) {
        plant->SetParent(tile);
        plant->position = Vector2((this->tileSize - plant->GetSize()) / 2);
        return true;
    } else {
        return false;
    }
}
void PlantContainer::PlaceHologram(Texture* icon, const Vector2& position) {
    MapTile* tile = this->GetByPosition(position);
    if (tile != nullptr && tile->children.size() == 2) {
        tile->hologram->texture = icon;
    }
}
void PlantContainer::ClearHologram() {
    for(int y=0; y<mapSize.y; y++) {
        for(int x=0; x<mapSize.x; x++) {
            MapTile* mapTile = this->tileBoxs[y][x];
            mapTile->hologram->texture = nullptr;
        }
    }
}
bool PlantContainer::ShovelPlant(const Vector2& position) {
    MapTile* tile = this->GetByPosition(position);
    if (tile != nullptr && tile->children.size() == 3) {
        Node* plant = tile->children[2];;
        tile->children.erase(tile->children.begin() + 2);
        plant->Delete();
        return true;
    } else {
        return false;
    }
}