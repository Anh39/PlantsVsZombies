#include "colorRect.h"

ColorRect::ColorRect() {
    this->Name = "ColorRect";
}
void ColorRect::Draw(Renderer* renderer, Vector2 absolutePosition) {
    Rect targetRect = this->GetRect();
    targetRect.SetPosition(absolutePosition);
    renderer->RenderRectangle(targetRect, this->color);
}
