#pragma once

#include "engine.h"
#include "Components/include.h"
#include <functional>

class BasePlant: public Node 
{
public:
    float sunCost = 0;
    float cardCooldown = 1;
    float heathPoint = 100;
    float cooldown = 5;
    float time = 0;

    BasePlant();
    ~BasePlant();
    
    virtual BasePlant* Create();
    virtual void SetSize(const Vector2& size);
    virtual Vector2 GetSize();
    virtual Texture* GetIcon();

    void Update(float delta) override;
protected:
    Vector2 size;
    PlantColliderBox* hitbox;
};