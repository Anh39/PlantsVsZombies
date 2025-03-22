#include "textureRect.h"
#include "drawFunctions.h"
#include <iostream>

TextureRect::TextureRect() {
    this->texture = nullptr;
}
void TextureRect::Draw(Renderer* renderer, Vector2F absolutePosition) {
    Rect targetRect = Rect(absolutePosition.x, absolutePosition.y, this->rect.w, this->rect.h);
    // targetRect.setPosition(absolutePosition);
    RenderWithoutBackground(renderer, this->texture, this->rect);
}

// void TextureRect::update(float delta) {

// }

// string TextureRect::GetClassName() {
//     return string(this->className);
// }