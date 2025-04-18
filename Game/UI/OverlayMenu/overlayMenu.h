#pragma once
#include "engine.h"
#include "Components/include.h"
#include "../Components/include.h"


class OverlayMenuScene: public Scene
{
public:
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