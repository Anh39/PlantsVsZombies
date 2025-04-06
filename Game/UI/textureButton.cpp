#include "button.h"

TextureButton::TextureButton() {
    this->onTextureRect = new TextureRect();
    this->offTextureRect = new TextureRect();
    this->AddChildren(this->onTextureRect);
    this->AddChildren(this->offTextureRect);
    this->onTextureRect->isVisible = false;
    this->offTextureRect->isVisible = true;
}
TextureButton::~TextureButton() {
}
void TextureButton::Update(float delta) {
    Rect rect = this->onTextureRect->GetRect();
    rect.SetPosition(this->GetAbsolutePosition());
    if (rect.Contain(MouseEvent::Position())) {
        this->onTextureRect->isVisible = true;
        this->offTextureRect->isVisible = false;
        if (MouseEvent::JustReleased(MouseType::MouseLeft)) {
            if (this->OnClicked) {
                this->OnClicked();
            }
        }
    } else {
        this->onTextureRect->isVisible = false;
        this->offTextureRect->isVisible = true;
    }
}
void TextureButton::SetSize(const Vector2& size) {
    this->onTextureRect->size = size;
    this->offTextureRect->size = size;
}
