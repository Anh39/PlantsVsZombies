#include "colorRect.h"

ColorRect::ColorRect() {

}
void ColorRect::Draw(Renderer* renderer, Vector2 absolutePosition) {
    Rect targetRect = this->rect;
    targetRect.SetPosition(absolutePosition);
    renderer->RenderRectangle(targetRect, this->color);
}
