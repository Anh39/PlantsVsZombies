#pragma once

#include "basePlant.h"
#include "../spriteRect.h"
#include "Components/include.h"

class Wallnut: public BasePlant
{
public:
    Wallnut();
    ~Wallnut();

    BasePlant* Create() override;
    Texture* GetIcon() override;
    void SetSize(const Vector2& size) override;
    Vector2 GetSize() override;
    void Update(float delta) override;
private:
    void HideAll();
    SpriteRect* spriteRect1;
    SpriteRect* spriteRect2;
    SpriteRect* spriteRect3;
    SpriteRect* spriteRect4;
};
