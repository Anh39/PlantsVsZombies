#pragma once

#include "engine.h"
#include "trophy.h"

class WinOverlay: public EventNode
{
public:
    std::function<void()> OnEnd;
    WinOverlay();
    ~WinOverlay();

    void Start();
    void Update(float delta) override;
    void ProcessEvent(Event* event) override;
private:
    Trophy* trophy;
};