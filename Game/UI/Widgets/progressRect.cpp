#include "progressRect.h"

ProgressRect::ProgressRect() {
    this->percent = 0;
}
ProgressRect::~ProgressRect() {

}

void ProgressRect::Progress(float percent) {
    this->percent = percent;
}

void ProgressRect::Draw(Renderer* renderer, Vector2 absolutePosition) {
    if (this->texture == nullptr || this->texture->SDL() == nullptr) return;
    Rect targetRect = this->GetRect();
    targetRect.SetPosition(absolutePosition);
    int w, h;
    SDL_QueryTexture(this->texture->SDL(), NULL, NULL, &w, &h);
    Rect srcRect = Rect(0, 0, w*percent, h);
    targetRect.w *= percent;
    renderer->RenderTexture(srcRect, targetRect, this->texture);
}