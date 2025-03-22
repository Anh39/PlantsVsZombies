#include "colorRect.h"
#include "drawFunctions.h"

ColorRect::ColorRect() {

}
void ColorRect::Draw(Renderer* renderer, Vector2F absolutePosition) {
    Rect targetRect = Rect(absolutePosition.x, absolutePosition.y, this->rect.w, this->rect.h);
    renderRectangle(renderer, targetRect, this->color);
}

// string ColorRect::GetClassName() {
//     return string(this->className);
// }