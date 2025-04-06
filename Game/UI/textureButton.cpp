#include "button.h"

TextureButton::TextureButton() {
    this->OnTextureRect = new TextureRect();
    this->OffTextureRect = new TextureRect();
    this->AddChildren(this->OnTextureRect);
    this->AddChildren(this->OffTextureRect);
    this->OnTextureRect->isVisible = false;
    this->OffTextureRect->isVisible = true;
}
TextureButton::~TextureButton() {
}
void TextureButton::Update(float delta) {
    Rect rect = this->OnTextureRect->GetRect();
    rect.SetPosition(this->GetAbsolutePosition());
    if (rect.Contain(MouseEvent::Position())) {
        this->OnTextureRect->isVisible = true;
        this->OffTextureRect->isVisible = false;
        if (MouseEvent::JustReleased(MouseType::MouseLeft)) {
            if (this->OnClicked) {
                this->OnClicked();
            }
        }
    } else {
        this->OnTextureRect->isVisible = false;
        this->OffTextureRect->isVisible = true;
    }
}
void TextureButton::SetSize(const Vector2& size) {
    this->OnTextureRect->size = size;
    this->OffTextureRect->size = size;
}
