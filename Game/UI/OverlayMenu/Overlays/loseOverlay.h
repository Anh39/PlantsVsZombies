#pragma once

#include "engine.h"

class LoseOverlay: public EventNode
{
public:
    LoseOverlay();
    ~LoseOverlay();

    void Start();
    void Update(float delta) override;
    void ProcessEvent(Event* event) override;
private:
    TextureRect* background;
};