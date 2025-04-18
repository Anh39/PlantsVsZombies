#pragma once

#include "engine.h"

class LoseOverlay: public Node
{
public:
    LoseOverlay();
    ~LoseOverlay();

    void Start();
    void Update(float delta) override;
private:
    TextureRect* background;
};