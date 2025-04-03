#pragma once
#include "engine.h"
#include "../Plants/basePlant.h"

class PlantCard: public Node {
public:
    PlantCard();
    ~PlantCard();

    void SetTarget(BasePlant* target);
    void Update(float delta) override;
    void SetTargetSize(const Vector2& size);
    BasePlant* CreateTarget();

    bool isMoving;
    Vector2 startPosition;
    Vector2 startMousePosition;
private:
    Vector2 childSize;
    BasePlant* target;
    BasePlant* instanceTarget;
};