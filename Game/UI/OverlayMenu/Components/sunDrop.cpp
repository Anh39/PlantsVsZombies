#include "sunDrop.h"

SunDrop::SunDrop() {
    this->core = new Texture("asset/menu/Sun1.png");
    this->middle = new Texture("asset/menu/Sun2.png");
    this->outer = new Texture("asset/menu/Sun3.png");
    this->middleDegree = 0;
    this->outerDegree = 0;
    this->velocity = Vector2(0, 0);
    this->isCollected = false;

    this->maxY = 1000;
    this->disappearCooldown = 5;
    this->disappearTime = this->disappearCooldown;
}

SunDrop::~SunDrop() {
    delete this->core;
    delete this->middle;
    delete this->outer;
}
void SunDrop::Update(float delta) {
    this->position += this->velocity * delta;
    if (this->position.y > this->maxY) {
        this->position.y = this->maxY;
    }
    if (this->position.y >= this->maxY) {
        this->disappearTime -= delta;
        if (this->disappearTime < 0) {
            this->Delete();
        }
    }

    this->middleDegree += delta * 60;
    this->outerDegree -= delta * 45;
    
    if (this->middleDegree > 360) this->middleDegree -= 360;
    if (this->outerDegree < 0) this->outerDegree += 360;

    if (this->isCollected) {
        if ((this->GetAbsolutePosition() - this->collectDestination).GetSqrLength() < 1) {
            this->Delete();
        }
    }

    Rect rect = this->GetRect();
    rect.SetPosition(this->GetAbsolutePosition());
    if (MouseEvent::JustPressed(MouseType::MouseLeft) && rect.Contain(MouseEvent::Position())) {
        if (!this->isCollected && this->OnClicked) {
            this->OnClicked(this);
        }
    }
}
void SunDrop::Collect(Vector2 destination, float time) {
    this->isCollected = true;
    this->collectDestination = destination;
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