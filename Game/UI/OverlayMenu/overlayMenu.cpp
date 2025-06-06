#include "overlayMenu.h"
#include "../../Levels/all.h"
using namespace std;

OverlayMenuScene::OverlayMenuScene(string levelName) {
    cout << "Start game level " << levelName << endl;
    Level* level = GenerateLevel(levelName);

    TextureRect* background = new TextureRect();
    background->texture = new Texture("asset/menu/background1.jpg");
    const float widthOffset = 1920 * 0.275;
    background->position = Vector2(-widthOffset, 0);
    const float width = 1920 * 1.75;
    background->size = Vector2(width, 1080);
    

    this->menuButton = new MenuButton();
    this->menuButton->position = Vector2(1920-275, 0);
    this->menuButton->SetSize(Vector2(175, 75));
    this->menuButton->SetText("Menu");
    this->menuButton->SetColor(Color(0, 255, 0));
    this->menuButton->OnClicked = [this]() {
        GameLoop::Pause();
        this->menuButton->isVisible = false;
        this->optionMenu->isVisible = true;
    };

    this->optionMenu = new OptionMenu(false);
    this->optionMenu->position = Vector2(0, 0);
    this->optionMenu->isVisible = false;
    this->optionMenu->OnBackToTitle = [this]() {
        GameLoop::Resume();
        if (this->BackTitleFunction) {
            this->BackTitleFunction();
        }
    };
    this->optionMenu->OnBackToGame = [this]() {
        GameLoop::Resume();
        this->optionMenu->isVisible = false;
        this->menuButton->isVisible = true;
    };
    this->optionMenu->position = Vector2(1920, 1080)/2-this->optionMenu->GetSize()/2;

    this->sunBank = new SunBank();
    this->sunBank->position = Vector2(25, 0);
    this->sunBank->SetSize(Vector2(125, 150));

    this->seedBank = new SeedBank(9);
    this->seedBank->position = Vector2(25+125, 0);
    this->seedBank->SetSize(Vector2(800, 150));
    this->seedBank->updateCardSunCostFunction = [this]() {
        this->seedBank->UpdateCardSunCostOverlay(this->sunBank->Amount);
    };

    this->shovelBank = new ShovelBank();
    this->shovelBank->position = Vector2(25+125+800, 0);
    this->shovelBank->SetSize(Vector2(150, 150), Vector2(12, 12));

    this->waveProgressBar = new WaveProgressBar(level->zombieWaves);
    this->waveProgressBar->position = Vector2(1920 - 350 - 25, 1080 - 75 - 15);
    this->waveProgressBar->SetSize(Vector2(350, 76));
    this->waveProgressBar->SetProgress(0);
    this->waveProgressBar->SetTargetProgress(0);


    this->sunController = new SunController();

    Vector2 mapSize = Vector2(1770, 900);
    Vector2 mapGridSize = Vector2(9, 5);
    this->map = new Map(mapSize, mapGridSize, level->zombieWaves);
    this->map->position = Vector2(70, 130);

    for(BasePlant* plantTemplate: level->plants) {
        this->seedBank->AddNewCard(plantTemplate);
    }
    this->seedBank->SetPlantSize(Vector2(150, 150));


    this->startOverlay = new StartOverlay();
    this->startOverlay->Start();

    this->winOverlay = new WinOverlay();
    this->winOverlay->OnEnd = [this]() {
        if (this->BackToAdventureFunction) {
            this->BackToAdventureFunction();
        }
    };

    this->loseOverlay = new LoseOverlay();

    this->loseOverlay->ToTitleFunction = [this]() {
        if(this->BackTitleFunction) {
            this->BackTitleFunction();
        }
    };



    this->root->AddChildren(background);

    this->root->AddChildren(this->map);
    this->root->AddChildren(this->optionMenu);
    this->root->AddChildren(this->menuButton);
    this->root->AddChildren(this->seedBank);
    this->root->AddChildren(this->shovelBank);
    this->root->AddChildren(this->sunBank);

    this->root->AddChildren(this->sunController);
    this->root->AddChildren(this->waveProgressBar);

    this->root->AddChildren(this->startOverlay);
    this->root->AddChildren(this->loseOverlay);
    this->root->AddChildren(this->winOverlay);
}

OverlayMenuScene::~OverlayMenuScene() {

}

