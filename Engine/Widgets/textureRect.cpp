#include "textureRect.h"
#include "drawFunctions.h"
#include <iostream>

TextureRect::TextureRect() {
    this->texture = nullptr;
}
void TextureRect::draw(Renderer* renderer, Vector2F absolutePosition) {
    Rect targetRect = Rect(absolutePosition.x, absolutePosition.y, this->rect.w, this->rect.h);
    // targetRect.setPosition(absolutePosition);
    renderWithoutBackground(renderer, this->texture, this->rect);
}

// void TextureRect::update(float delta) {

// }