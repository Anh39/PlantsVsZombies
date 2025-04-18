#include "adventureMode.h"
#include "levelSelect.h"
#include "../Widgets/include.h"

AdventureModeScene::AdventureModeScene() {
    TextureRect* background = new TextureRect();
    background->texture = new Texture("asset/menu/Challenge_Background.jpg");
    background->position = Vector2(0, 0);
    background->size = Vector2(1920, 1080);

    TextRect* titleTextRect = new TextRect();
    titleTextRect->SetText("Adventure mode");
    titleTextRect->position = Vector2(810, 60);
    titleTextRect->size = Vector2(300, 50);
    titleTextRect->SetColor(Color(0, 0, 0));

    Vector2 gridSize = Vector2(8, 4);
    LevelSelectMenu* levelSelectMenu = new LevelSelectMenu(gridSize);
    levelSelectMenu->position = Vector2(60, 180);
    levelSelectMenu->SetSize(Vector2(1800, 800));
    levelSelectMenu->SetSpacing(Vector2(25, 25));
    int count = 0;
    for(int y=0; y<gridSize.y; y++) {
        for(int x=0; x<gridSize.x; x++) {
            count += 1;
            levelSelectMenu->cards[y][x]->OnClicked = [this, count]() {
                if (this->StartGameLevelFunction) {
                    this->StartGameLevelFunction(std::to_string(count));
                }
            };
        }
    }

    this->root->AddChildren(background);
    this->root->AddChildren(titleTextRect);
    this->root->AddChildren(levelSelectMenu);
}

AdventureModeScene::~AdventureModeScene() {

}