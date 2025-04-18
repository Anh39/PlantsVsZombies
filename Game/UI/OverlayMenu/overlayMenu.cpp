#include "overlayMenu.h"

using namespace std;

OverlayMenuScene::OverlayMenuScene(string level) {
    cout << "Start game level " << level << endl;
    TextureRect* background = new TextureRect();
    background->texture = new Texture("asset/menu/background1.jpg");
    const float widthOffset = 1920 * 0.275;
    background->position = Vector2(-widthOffset, 0);
    const float width = 1920 * 1.75;
    background->size = Vector2(width, 1080);
    
    this->root->AddChildren(background);

    this->menuButton = new MenuButton();
    this->menuButton->position = Vector2(1920-275, 0);
    this->menuButton->SetSize(Vector2(175, 75));
    this->menuButton->SetText("Menu");
    this->menuButton->SetColor(Color(0, 255, 0));
    this->menuButton->OnClicked = [this]() {
        this->menuButton->isVisible = false;
        this->optionMenu->isVisible = true;
    };
    this->root->AddChildren(this->menuButton);

    this->optionMenu = new OptionMenu();
    this->optionMenu->position = Vector2(0, 0);
    this->optionMenu->isVisible = false;
    this->optionMenu->OnBackToGame = [this]() {
        this->optionMenu->isVisible = false;
        this->menuButton->isVisible = true;
    };
    this->optionMenu->position = Vector2(1920, 1080)/2-this->optionMenu->GetSize()/2;
    this->root->AddChildren(this->optionMenu);

    this->sunBank = new SunBank();
    this->sunBank->position = Vector2(25, 0);
    this->sunBank->SetSize(Vector2(125, 150));
    this->root->AddChildren(this->sunBank);

    this->seedBank = new SeedBank();
    this->seedBank->position = Vector2(25+125, 0);
    this->seedBank->SetSize(Vector2(800, 150));
    this->root->AddChildren(this->seedBank);

    this->shovelBank = new ShovelBank();
    this->shovelBank->position = Vector2(25+125+800, 0);
    this->shovelBank->SetSize(Vector2(150, 150), Vector2(12, 12));
    this->root->AddChildren(this->shovelBank);

    this->waveProgressBar = new WaveProgressBar();
    this->waveProgressBar->position = Vector2(1920 - 350 - 25, 1080 - 75 - 15);
    this->waveProgressBar->SetSize(Vector2(350, 76));
    this->waveProgressBar->SetNumWave(4);
    this->waveProgressBar->SetProgress(0);
    this->root->AddChildren(this->waveProgressBar);

    this->sunController = new SunController();
    this->root->AddChildren(this->sunController);
    PeaShooter* shooter = new PeaShooter();
    shooter->position = Vector2(500, 300);
    shooter->isActive = true;
    this->root->AddChildren(shooter);
    CherryBomb* cherry =  new CherryBomb();
    cherry->position = Vector2(600,300);
    cherry->isActive = true;
    this->root->AddChildren(cherry);
    Sunflower* sunflower = new Sunflower();
    sunflower->position = Vector2(700, 300);
    sunflower->isActive = true;
    this->root->AddChildren(sunflower);
    PotatoMine* potato = new PotatoMine();
    potato->position = Vector2(800, 300);
    potato->isActive = true;
    this->root->AddChildren(potato);
}

OverlayMenuScene::~OverlayMenuScene() {

}