#pragma once
#include "engine.h"
#include "menuButton.h"
#include "sunBank.h"
#include "seedBank.h"
#include "shovelBank.h"
#include "waveProgressBar.h"
#include "sunDrop.h"
#include "sunController.h"
#include "../Components/optionMenu.h"

class OverlayMenuScene: public Scene
{
public:
    OverlayMenuScene(std::string level);
    ~OverlayMenuScene();

private:
    OptionMenu* optionMenu;
    MenuButton* menuButton;
    SunBank* sunBank;
    SeedBank* seedBank;
    ShovelBank* shovelBank;
    WaveProgressBar* waveProgressBar;
    SunController* sunController;

};