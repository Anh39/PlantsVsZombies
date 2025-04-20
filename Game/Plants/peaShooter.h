#pragma once

#include "basePlant.h"
#include "../spriteRect.h"


class PeaShooter: public BasePlant
{
public:
    float damage = 10;
    float range; // n tiles ahead

    PeaShooter();
    ~PeaShooter();

    BasePlant* Create() override;
    void SetSize(const Vector2& size) override;
    Vector2 GetSize() override;
    Texture* GetIcon();

    void Update(float delta) override;
private:
    bool isAttack = false;
    PlantColliderBox* hitbox;
    PlantDetectorColliderBox* detectorBox;
    SpriteRect* idleSpriteRect;
    SpriteRect* attackSpriteRect;
};