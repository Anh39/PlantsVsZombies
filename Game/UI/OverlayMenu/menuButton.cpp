#include "menuButton.h"
#include <math.h>
using namespace std;

MenuButton::MenuButton() {
    this->leftTexture = new TextureRect();
    this->leftTexture->texture = new Texture("asset/menu/button_left.png");
    this->middleTexture = new TextureRect();
    this->middleTexture->texture = new Texture("asset/menu/button_middle.png");
    this->rightTexture = new TextureRect();
    this->rightTexture->texture = new Texture("asset/menu/button_right.png");

    this->textRect = new TextRect();

    this->AddChildren(leftTexture);
    this->AddChildren(middleTexture);
    this->AddChildren(rightTexture);
    this->AddChildren(textRect);
}

MenuButton::~MenuButton() {

}
void MenuButton::Update(float delta) {
    Rect rect = Rect();
    rect.SetPosition(this->GetAbsolutePosition());
    rect.SetSize(this->size);
    if (rect.Contain(MouseEvent::Position())) {
        unsigned char r = min(this->color.r + 128, 255);
        unsigned char g = min(this->color.g + 128, 255);
        unsigned char b = min(this->color.b + 128, 255);
        this->textRect->SetColor(Color(r, g, b));
        if (MouseEvent::JustReleased(MouseType::MouseLeft)) {
            if (this->OnClicked) {
                this->OnClicked();
            }
        }
    } else {
        this->textRect->SetColor(this->color);
    }
}
void MenuButton::SetSize(const Vector2& inputSize) {
    Vector2 size = inputSize;
    if (size.x < 50) size.x = 50;
    if (size.y < 30) size.y = 30;
    this->size = size;
    float leftWidth = 25;
    float minThirdHeight = 10;
    this->leftTexture->position = Vector2(0, 0);
    this->leftTexture->size = Vector2(leftWidth, size.y);
    this->middleTexture->position = Vector2(leftWidth, 0);
    this->middleTexture->size = Vector2(size.x-leftWidth*2, size.y);
    this->rightTexture->position = Vector2(size.x-leftWidth, 0);
    this->rightTexture->size = Vector2(leftWidth, size.y);
    
    this->textRect->position = Vector2(this->middleTexture->position.x, minThirdHeight);
    this->textRect->size = Vector2(this->middleTexture->size.x, this->middleTexture->size.y - 3* minThirdHeight);
}
void MenuButton::SetText(string text) {
    this->textRect->SetText(text);
}
void MenuButton::SetColor(const Color& color) {
    this->color = color;
    this->textRect->SetColor(color);
}
