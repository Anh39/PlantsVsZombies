#pragma once

#include "engine.h"
#include <vector>
#include "plantCard.h"
#include "../../../level.h"
#include <functional>

class SeedBank: public Node
{
public:
    std::function<void()> updateCardSunCostFunction;
    SeedBank(int maxSlots);
    ~SeedBank();
    void SetSize(const Vector2& size);

    void SetPlantSize(const Vector2& size);
    Vector2 GetPlantSize();

    void AddNewCard(BasePlant* templatePlant);
    void UpdateCardSunCostOverlay(float sunAmount);
    void Update(float delta) override;
private:

    int maxSlots;
    Vector2 plantSize;
    Vector2 size;
    TextureRect* background;
    std::vector<PlantCard*> cards;
};