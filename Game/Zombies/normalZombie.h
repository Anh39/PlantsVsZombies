#pragma once

#include "baseZombie.h"
#include "../spriteRect.h"

class NormalZombie: public BaseZombie
{
public:
    NormalZombie();
    ~NormalZombie();

    void Update(float delta) override;
    void SetSize(const Vector2& size) override;
private:
    float relayDelta;
    bool isAttack = false;
    bool isDead = false;
    SpriteRect* walkingSpriteRect;
    SpriteRect* attackSpriteRect;
    SpriteRect* dieSpriteRect;
};