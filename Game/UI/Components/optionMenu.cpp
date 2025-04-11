#include "optionMenu.h"


OptionMenu::OptionMenu() {
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
}

OptionMenu::~OptionMenu() {

}

Vector2 OptionMenu::GetSize() {
    return Vector2(680, 800);
}