#include "trophy.h"

Trophy::Trophy() {
    this->trophyTexture = new Texture("asset/menu/trophy_hi_res.png");
    this->glowTexture = new Texture("asset/menu/AwardPickupGlow.png");
    this->rayTexture1 = new Texture("asset/menu/AwardRays.png");
    this->rayTexture2 = new Texture("asset/menu/AwardRays.png");
    this->size = Vector2(1920, 1080);
    this->rotationSpeed = 60;
    this->rayDegree1 = 0;
    this->rayDegree2 = 0;
    this->scale = 1;
    this->started = false;
}

Trophy::~Trophy() {
    delete this->trophyTexture;
    delete this->glowTexture;
    delete this->rayTexture1;;
    delete this->rayTexture2;
}

void Trophy::Start() {
    this->scale = 0.1;
    this->started = true;
}
void Trophy::Update(float delta) {
    this->rayDegree1 += this->rotationSpeed * delta;
    this->rayDegree2 -= this->rotationSpeed * delta / 2;
    if (this->rayDegree1 > 360) this->rayDegree1 = 0;
    if (this->rayDegree2 < 0) this->rayDegree2 = 360;
    if (this->started) {
        if (this->scale < 1) {
            this->scale += this->scaleSpeed * delta;
        } else {
            this->scale = 1;
            if (this->OnEnd) {
                this->OnEnd();
            }
            this->started = false;
        }
    }

}
void Trophy::Draw(Renderer* renderer, Vector2 absolutePosition) {
    Rect targetRect = Rect();
    Vector2 originalSize = this->size;

    Vector2 raySize = Vector2(1920, 1920) * this->scale;
    targetRect.SetPosition((this->size*this->scale - raySize)/2);
    targetRect.SetSize(raySize);
    renderer->RenderTextureEx(targetRect, this->rayTexture1, this->rayDegree1);
    renderer->RenderTextureEx(targetRect, this->rayTexture2, this->rayDegree2);

    Vector2 glowSize = Vector2(800, 800) * this->scale;
    targetRect.SetPosition((this->size*this->scale - glowSize)/2);
    targetRect.SetSize(glowSize);
    renderer->RenderTexture(targetRect, this->glowTexture);

    Vector2 trophySize = Vector2(400, 400) * this->scale;
    targetRect.SetPosition((this->size*this->scale - trophySize)/2);
    targetRect.SetSize(trophySize);
    renderer->RenderTexture(targetRect, this->trophyTexture);
}