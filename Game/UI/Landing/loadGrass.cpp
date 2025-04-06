#include "loadGrass.h"

LoadGrass::LoadGrass() {
    this->percent = 0;
}
LoadGrass::~LoadGrass() {

}

void LoadGrass::Progress(float percent) {
    this->percent = percent;
}

void LoadGrass::Draw(Renderer* renderer, Vector2 absolutePosition) {
    if (this->texture == nullptr || this->texture->SDL() == nullptr) return;
    Rect targetRect = this->GetRect();
    targetRect.SetPosition(absolutePosition);
    int w, h;
    SDL_QueryTexture(this->texture->SDL(), NULL, NULL, &w, &h);
    Rect srcRect = Rect(0, 0, w*percent, h);
    targetRect.w *= percent;
    renderer->RenderTexture(srcRect, targetRect, this->texture);
}