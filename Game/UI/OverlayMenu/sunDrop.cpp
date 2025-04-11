#include "sunDrop.h"

SunDrop::SunDrop() {
    this->core = new Texture("asset/menu/Sun1.png");
    this->middle = new Texture("asset/menu/Sun2.png");
    this->outer = new Texture("asset/menu/Sun3.png");
    this->middleDegree = 0;
    this->outerDegree = 0;
    this->velocity = Vector2(0, 0);
    this->isCollected = false;
}

SunDrop::~SunDrop() {
    delete this->core;
    delete this->middle;
    delete this->outer;
}
void SunDrop::Update(float delta) {
    this->position += this->velocity * delta;

    this->middleDegree += delta * 60;
    this->outerDegree -= delta * 45;
    
    if (this->middleDegree > 360) this->middleDegree -= 360;
    if (this->outerDegree < 0) this->outerDegree += 360;

    if (this->isCollected) {
        if ((this->GetAbsolutePosition() - this->destination).GetSqrLength() < 1) {
            this->Delete();
        }
    }

    Rect rect = this->GetRect();
    rect.SetPosition(this->GetAbsolutePosition());
    if (MouseEvent::JustPressed(MouseType::MouseLeft) && rect.Contain(MouseEvent::Position())) {
        if (this->OnClicked) {
            this->OnClicked(this);
        }
    }
}
void SunDrop::Collect(Vector2 destination, float time) {
    this->isCollected = true;
    this->destination = destination;
    this->moveTime = time;
    this->velocity = (destination - this->GetAbsolutePosition())/time;
}
void SunDrop::Draw(Renderer* renderer, Vector2 absolutePosition) {
    Rect targetRect = Rect();
    Vector2 originalSize = this->size;
    Vector2 sizeStep = this->size/3;

    targetRect.SetPosition(absolutePosition);
    targetRect.SetSize(originalSize);
    renderer->RenderTextureEx(targetRect, this->outer, this->outerDegree);

    targetRect.SetPosition(absolutePosition+sizeStep/2);
    targetRect.SetSize(originalSize-sizeStep);
    renderer->RenderTextureEx(targetRect, this->middle, this->middleDegree);

    targetRect.SetPosition(absolutePosition+sizeStep);
    targetRect.SetSize(originalSize-sizeStep*2);
    renderer->RenderTexture(targetRect, this->core);
}