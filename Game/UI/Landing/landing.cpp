#include "landing.h"
#include "loadingController.h"
#include <functional>

LandingScene::LandingScene() {
    LoadingController* controller = new LoadingController();

    TextureRect* background = new TextureRect();
    Texture* backgroundImage = new Texture("asset/menu/titlescreen.jpg");
    background->texture = backgroundImage;
    background->position = Vector2(0, 0);
    background->size = Vector2(1920, 1080);
    
    LoadBar* loadBar = new LoadBar();
    loadBar->position = Vector2(710, 900);

    this->root->AddChildren(controller);
    this->root->AddChildren(background);
    this->root->AddChildren(loadBar);

    controller->startFunction = [loadBar]() {loadBar->Start();};
    controller->progressFuntion = [loadBar](float percent) {loadBar->Progress(percent);};
    controller->completeFunction = [loadBar]() {loadBar->Stop();};
    loadBar->startGameFunction = [](){std::cout << "Start game\n";};
}
LandingScene::~LandingScene() {

}