#pragma once
#include "engine.h"
#include "Components/include.h"
#include "../Components/include.h"
#include <functional>

class OverlayMenuScene: public Scene
{
public:
    std::function<void()> BackTitleFunction;
    OverlayMenuScene(std::string levelName);
    ~OverlayMenuScene();

private:
    OptionMenu* optionMenu;
    MenuButton* menuButton;
    SunBank* sunBank;
    SeedBank* seedBank;
    ShovelBank* shovelBank;
    WaveProgressBar* waveProgressBar;
    SunController* sunController;

    PlantContainer* plantContainer;
};