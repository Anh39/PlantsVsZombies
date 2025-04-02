#pragma once
#include "engine.h"
#include "../Plants/basePlant.h"

class PlantCard: public Node {
public:
    PlantCard();
    ~PlantCard();

    const string GetClassName() override {return "PlantCard";}
    void SetTarget(BasePlant* target);
    void Update(float delta) override;
    BasePlant* CreateTarget();

    bool isMoving;
    Vector2 startPosition;
    Vector2 startMousePosition;
private:
    BasePlant* target;
    BasePlant* instanceTarget;
};