#pragma once
#include "engine.h"
#include <functional>

class TitleMenuScene: public Scene
{
public:
    std::function<void()> switchAdventureModeFunction;

    TitleMenuScene();
    ~TitleMenuScene();
};