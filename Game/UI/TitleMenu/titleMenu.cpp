#include "titleMenu.h"
#include "../button.h"

TitleMenuScene::TitleMenuScene() {
    TextureRect* background = new TextureRect();
    background->texture = new Texture("asset/menu/SelectorScreen_BG.jpg");
    background->position = Vector2(0, 0);
    background->size = Vector2(1920, 1080);

    TextureRect* backgroundLeft = new TextureRect();
    backgroundLeft->texture = new Texture("asset/menu/SelectorScreen_BG_Left_P.png");
    backgroundLeft->position = Vector2(0, 0);
    backgroundLeft->size = Vector2(756, 1080);

    TextureRect* backgroundCenter = new TextureRect();
    backgroundCenter->texture = new Texture("asset/menu/SelectorScreen_BG_Center_P.png");
    backgroundCenter->position = Vector2(200, 560);
    backgroundCenter->size = Vector2(1481, 720);

    TextureRect* backgroundRight = new TextureRect();
    backgroundRight->texture = new Texture("asset/menu/SelectorScreen_BG_Right_P.png");
    backgroundRight->position = Vector2(546, 26);
    backgroundRight->size = Vector2(1374, 1054);

    Node* modeButtons = new Node();
    modeButtons->position = Vector2(1175, 100);

    Node* optionButtons = new Node();
    optionButtons->position = Vector2(1475, 860);

    this->root->AddChildren(background);
    this->root->AddChildren(backgroundCenter);
    this->root->AddChildren(backgroundLeft);
    this->root->AddChildren(backgroundRight);
    this->root->AddChildren(modeButtons);
    this->root->AddChildren(optionButtons);

    Vector2 adventureSize = Vector2(600, 300);
    float shadowThickness = 16;

    TextureButton* adventureButton = new TextureButton();
    adventureButton->OffTextureRect->texture = new Texture("asset/menu/SelectorScreen_StartAdventure_Button1.png");
    adventureButton->OnTextureRect->texture = new Texture("asset/menu/SelectorScreen_StartAdventure_Highlight.png");
    adventureButton->SetSize(adventureSize);

    TextureRect* adventureShadow = new TextureRect();
    adventureShadow->texture = new Texture("asset/menu/SelectorScreen_Shadow_Adventure.png");
    adventureShadow->size = Vector2(adventureSize.x+shadowThickness*2, adventureSize.y+shadowThickness*2);
    adventureShadow->position = Vector2(-shadowThickness, -shadowThickness);

    modeButtons->AddChildren(adventureShadow);
    modeButtons->AddChildren(adventureButton);

    TextureButton* optionButton = new TextureButton();
    optionButton->OffTextureRect->texture = new Texture("asset/menu/SelectorScreen_Options1.png");
    optionButton->OnTextureRect->texture = new Texture("asset/menu/SelectorScreen_Options2.png");
    optionButton->SetSize(Vector2(150, 75));

    TextureButton* helpButton = new TextureButton();
    helpButton->OffTextureRect->texture = new Texture("asset/menu/SelectorScreen_Help1.png");
    helpButton->OnTextureRect->texture = new Texture("asset/menu/SelectorScreen_Help2.png");
    helpButton->SetSize(Vector2(100, 75));
    helpButton->position = Vector2(150, 50);

    TextureButton* quitButton = new TextureButton();
    quitButton->OffTextureRect->texture = new Texture("asset/menu/SelectorScreen_Quit1.png");
    quitButton->OnTextureRect->texture = new Texture("asset/menu/SelectorScreen_Quit2.png");
    quitButton->SetSize(Vector2(110, 90));
    quitButton->position = Vector2(275, 15);
    
    optionButtons->AddChildren(optionButton);
    optionButtons->AddChildren(helpButton);
    optionButtons->AddChildren(quitButton);

    adventureButton->OnClicked = [this]() {
        if (this->switchAdventureModeFunction) {
            this->switchAdventureModeFunction();
        }
    };
}

TitleMenuScene::~TitleMenuScene() {

}