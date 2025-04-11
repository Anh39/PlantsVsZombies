#include "levelCard.h"

LevelCard::LevelCard() {
    this->onBackground = new TextureRect();
    this->onBackground->texture = new Texture("asset/menu/Challenge_Window_Highlight.png");
    this->offBackground = new TextureRect();
    this->offBackground->texture = new Texture("asset/menu/Challenge_Window.png");
    this->itemBackground = new TextureRect();
    this->itemBackground->texture = new Texture("asset/menu/Almanac_GroundDay.jpg");

    this->levelText = new TextRect();
    this->levelText->SetColor(Color(0, 0, 0));
    this->levelText->SetText("");

    this->AddChildren(this->itemBackground);
    this->AddChildren(this->offBackground);
    this->AddChildren(this->onBackground);
    this->AddChildren(this->levelText);

    this->onBackground->isVisible = false;
    this->offBackground->isVisible = true;
}
LevelCard::~LevelCard() {

}
void LevelCard::SetSize(const Vector2& size) {
    this->onBackground->size = size;
    this->offBackground->size = size;
    this->itemBackground->position = Vector2(0.05*size.x, 0.05*size.y);
    this->itemBackground->size = Vector2(0.9*size.x, 0.6*size.y);

    float maxText = 10;
    float step = 1/maxText;
    float textLength = float(this->levelText->GetText().length());
    this->levelText->position = Vector2(step/2*size.x*(maxText-textLength), 0.675*size.y);
    this->levelText->size = Vector2(step*size.x*textLength, 0.2*size.y);
}
void LevelCard::Update(float delta) {
    Rect rect = this->onBackground->GetRect();
    rect.SetPosition(this->GetAbsolutePosition());
    if (rect.Contain(MouseEvent::Position())) {
        this->onBackground->isVisible = true;
        this->offBackground->isVisible = false;
        if (MouseEvent::JustReleased(MouseType::MouseLeft)) {
            if (this->OnClicked) {
                this->OnClicked();
            }
        }
    } else {
        this->onBackground->isVisible = false;
        this->offBackground->isVisible = true;
    }
}
std::string LevelCard::GetText() {
    return this->levelText->GetText();
}
void LevelCard::SetText(std::string text) {
    this->levelText->SetText(text);
}