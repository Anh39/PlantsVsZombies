#include "engine.h"
#include "UI/ui.h"
#include "UI/textRect.h"


int StartGame() {
    TextRect::font = TTF_OpenFont("asset/menu/Arial.TTF", 24);
    if (!TextRect::font) {
        std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
    }

    Scene::window->SetPosition(Vector2(50, 50));
    Scene::window->SetSize(Vector2(1280, 720));


    Scene* landing = new LandingScene();
    landing->SetAsCurrentScene();

    GameLoop::Start();
    TTF_Quit();
    return 0;
}