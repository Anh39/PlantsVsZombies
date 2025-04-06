#pragma once
#include "engine.h"
#include "loadbar.h"
#include <functional>

class LandingScene: public Scene {
public:
    std::function<void()> switchTitleMenuFuntion;

    LandingScene();
    ~LandingScene();

};