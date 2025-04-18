#include "game.h"
#include "engine.h"
#include "UI/ui.h"

void SwitchGameLevelScene(std::string level) {
    std::cout << "Game level\n";
    delete Scene::current;
    OverlayMenuScene* overlayMenu = new OverlayMenuScene(level);
    overlayMenu->SetAsCurrentScene();
    throw std::runtime_error("Switch scene");
}

void SwitchAdventureModeScene() {
    std::cout << "Adventure mode\n";
    delete Scene::current;
    AdventureModeScene* adventureMode = new AdventureModeScene();
    adventureMode->SetAsCurrentScene();
    adventureMode->StartGameLevelFunction = SwitchGameLevelScene;
    throw std::runtime_error("Switch scene");
}

void SwitchTitleMenuScene() {
    delete Scene::current;
    TitleMenuScene* title = new TitleMenuScene();
    title->SetAsCurrentScene();
    title->switchAdventureModeFunction = SwitchAdventureModeScene;
    throw std::runtime_error("Switch scene");
}
void StartLandingScene() {
    LandingScene* landing = new LandingScene();
    landing->SetAsCurrentScene();
    landing->switchTitleMenuFuntion = SwitchTitleMenuScene;
}
int StartGame() {
    TextRect::font = TTF_OpenFont("asset/menu/Arial.TTF", 24);
    if (!TextRect::font) {
        std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
    }

    Scene::window->SetPosition(Vector2(50, 50));
    Scene::window->SetSize(Vector2(1280, 720));

    StartLandingScene();

    GameLoop::Start();
    TTF_Quit();
    return 0;
}
