#include "optionMenu.h"


OptionMenu::OptionMenu(bool isTitle) {
    TextureRect* background = new TextureRect();
    background->texture = new Texture("asset/menu/options_menuback_P.png");
    background->size = Vector2(680, 800);

    MenuButton* backToGamebutton = new MenuButton();
    backToGamebutton->SetColor(Color(0, 255, 0));
    backToGamebutton->SetSize(Vector2(450, 110));
    backToGamebutton->position = Vector2(100, 650);
    backToGamebutton->SetText("Back to game");    

    this->AddChildren(background);
    this->AddChildren(backToGamebutton);

    backToGamebutton->OnClicked = [this]() {
        if (this->OnBackToGame) {
            this->OnBackToGame();
        }
    };

    if (!isTitle) {
        MenuButton* backTotitleButton = new MenuButton();
        backTotitleButton->SetColor(Color(0, 255, 0));
        backTotitleButton->SetText("Title");
        backTotitleButton->OnClicked = [this]() {
            if (this->OnBackToTitle) {
                this->OnBackToTitle();
            }
        };
        Vector2 buttonSize = Vector2(200, 100);
        backTotitleButton->SetSize(buttonSize);
        backTotitleButton->position = (background->size - buttonSize)/2;
        backTotitleButton->position.y = 500;
        this->AddChildren(backTotitleButton);
    }
}

OptionMenu::~OptionMenu() {

}

Vector2 OptionMenu::GetSize() {
    return Vector2(680, 800);
}