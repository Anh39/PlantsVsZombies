#include "textureRect.h"
#include <iostream>

TextureRect::TextureRect() {
    this->texture = nullptr;
}
void TextureRect::Draw(Renderer* renderer, Vector2 absolutePosition) {
    Rect targetRect = this->rect;
    targetRect.SetPosition(absolutePosition);
    renderer->RenderTexture(targetRect, this->texture);
}

// void TextureRect::update(float delta) {

// }

// string TextureRect::GetClassName() {
//     return string(this->className);
// }