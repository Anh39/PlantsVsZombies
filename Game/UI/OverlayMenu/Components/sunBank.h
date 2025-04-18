#pragma once

#include "engine.h"
#include "../../Widgets/include.h"
#include "sunController.h"

class SunBank: public EventNode
{
public:
    SunBank();
    ~SunBank();
    void SetSize(const Vector2& size);
    float Amount;
    void Update(float delta) override;
    void ProcessEvent(Event* event) override;
private:
    TextureRect* background;
    TextRect* counter;
};