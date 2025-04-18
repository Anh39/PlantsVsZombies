#pragma once

#include "engine.h"
#include "trophy.h"

class WinOverlay: public Node
{
public:
    std::function<void()> OnEnd;
    WinOverlay();
    ~WinOverlay();

    void Start();
    void Update(float delta) override;
private:
    Trophy* trophy;
};