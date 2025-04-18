#pragma once

#include "engine.h"
#include "../../../level.h"
#include "../../Components/include.h"
#include <functional>

class PlantCardPlacedEvent: public Event 
{
public:
    BasePlant* plant;
    Vector2 absolutePosition;
    std::function<void()> onSuccess;
    PlantCardPlacedEvent(BasePlant* plant, Vector2 absolutePosition) {
        this->plant = plant;
        this->absolutePosition = absolutePosition;
    };
    ~PlantCardPlacedEvent() {
        if (!this->handled) {
            plant->Delete();
        }
    };

};
class PlantCardHoverEvent: public Event
{
public:
    Texture* icon;
    Vector2 absolutePosition;
    PlantCardHoverEvent(Texture* icon, Vector2 absolutePosition) {
        this->icon = icon;
        this->absolutePosition = absolutePosition;
    }
    ~PlantCardHoverEvent() {
    }
};
class PlantCard: public Node
{
public:
    PlantCard();
    ~PlantCard();

    void Update(float delta) override;

    void SetTarget(BasePlant* target);
    BasePlant* CreateTarget();

    void SetSize(const Vector2& size);
    Vector2 GetSize();

    void SetPlantSize(const Vector2& size);
    Vector2 GetPlantSize();

    void UpdateSunCostOverlay(float sunAmount);
    Rect GetRect();
private:
    float time;
    bool isMoving;

    BasePlant* targetPlant;
    BasePlant* createdTarget;

    Vector2 cardSize;
    Vector2 plantSize;
    TextureRect* background;    
    TextureRect* iconRect;
    ColorRect* suncostOverlay;
    ColorRect* cooldownOverlay;
    TextRect* sunCostTextRect;

    void RefreshSunCost();
};