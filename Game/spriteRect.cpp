#include "spriteRect.h"

SpriteRect::SpriteRect() {
    this->Name = "SpriteRect";
    this->animationTime = 10;
    this->totalIndex = 0;
    this->currentIndex = 0;

}

SpriteRect::~SpriteRect() {
    delete this->texture;
}
void SpriteRect::Reset() {
    this->currentIndex = 0;
}
void SpriteRect::SetTexture(Texture* texture, Vector2 gridSize, int totalImages) {
    this->width = gridSize.x;
    this->height = gridSize.y;
    this->totalIndex = totalImages;
    this->texture = texture;
    if (this->texture != nullptr) {
        int w, h;
        SDL_QueryTexture(this->texture->SDL(), NULL, NULL, &w, &h);
        this->elementSize = Vector2(float(w)/this->width, float(h)/this->height);
    }
}
void SpriteRect::Step() {
    this->currentIndex++;
    if (this->currentIndex >= this->totalIndex) this->currentIndex = 0;
} 
Rect SpriteRect::GetCurrentRect() {
    int x = this->currentIndex % this->width;
    int y = this->currentIndex / this->width;
    Rect currentRect = Rect(
        this->elementSize.x * x,
        this->elementSize.y * y,
        this->elementSize.x,
        this->elementSize.y
    );
    return currentRect;
}
void SpriteRect::Draw(Renderer* renderer, Vector2 absolutePosition) {
    if (this->texture == nullptr || this->texture->SDL() == nullptr) return;
    Rect targetRect = this->GetRect();
    targetRect.SetPosition(absolutePosition);
    int w, h;
    SDL_QueryTexture(this->texture->SDL(), NULL, NULL, &w, &h);
    Rect srcRect = this->GetCurrentRect();
    renderer->RenderTexture(srcRect, targetRect, this->texture);
}

void SpriteRect::Update(float delta) {
    this->time += delta;
    if(this->time > this->animationTime / this->totalIndex) {
        this->time = 0;
        this->Step();
    }
}