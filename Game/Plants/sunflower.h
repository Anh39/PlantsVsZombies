#pragma once

#include "basePlant.h"
#include "../spriteRect.h"
#include "Components/include.h"

class Sunflower: public BasePlant
{
public:
    float sun;
    Sunflower();
    ~Sunflower();

    BasePlant* Create() override;
    Texture* GetIcon() override;
    void SetSize(const Vector2& size) override;
    Vector2 GetSize() override;
    void Update(float delta) override;
private:
    SpriteRect* spriteRect;
};