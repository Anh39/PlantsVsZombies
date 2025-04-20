#pragma once

#include "engine.h"
#include <functional>

class AdventureModeScene: public Scene
{
public:
    std::function<void(std::string)> StartGameLevelFunction;
    std::function<void()> BackToTitleFunction;
    AdventureModeScene();
    ~AdventureModeScene();
    int maxLevel = 1;
};