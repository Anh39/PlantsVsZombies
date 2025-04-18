#pragma once
#include "engine.h"
#include "Components/include.h"
#include "../Components/include.h"
#include "Overlays/include.h"
#include <functional>

class OverlayMenuScene: public Scene
{
public:
    std::function<void()> BackTitleFunction;
    std::function<void()> BackToAdventureFunction;
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

    Map* map;
    StartOverlay* startOverlay;
    WinOverlay* winOverlay;
    LoseOverlay* loseOverlay;
};