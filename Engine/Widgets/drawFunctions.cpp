#include "drawFunctions.h"

void RenderWithoutBackground(Renderer* renderer, Texture* texture, Rect rect) {
    if (texture != nullptr) {
        renderTexture(renderer, texture, rect);
    }
}
void RenderWithBackground(Renderer* renderer, Texture* texture, Rect rect, Color color) {
    if (texture != nullptr) {
        // if (rect.w == -1 || rect.h == -1) {
        //     Vector2 size = getImageSize(texture);
        //     rect.w = size.x;
        //     rect.h = size.y;
        // }
        renderTexture(renderer, texture, rect, color);
    }
}
