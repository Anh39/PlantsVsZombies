#include "textureRect.h"
#include <iostream>

TextureRect::TextureRect() {
    this->Name = "TextureRect";
    this->texture = nullptr;
}

void TextureRect::Draw(Renderer* renderer, Vector2 absolutePosition) {
    Rect targetRect = this->GetRect();
    targetRect.SetPosition(absolutePosition);
    renderer->RenderTexture(targetRect, this->texture);
}

TextureRect::~TextureRect() {
   delete this->texture;
}
