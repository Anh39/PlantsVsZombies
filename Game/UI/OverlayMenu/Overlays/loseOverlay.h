#pragma once

#include "engine.h"
#include "../Components/include.h"

class LoseOverlay: public EventNode
{
public:
    std::function<void()> ToTitleFunction;

    LoseOverlay();
    ~LoseOverlay();

    void Start();
    void Update(float delta) override;
    void ProcessEvent(Event* event) override;
private:
    TextureRect* background;
    MenuButton* titleButton;
};