#include "peaShooter.h"


PeaShooter::PeaShooter() {
    this->Name = "PeaShooter";
    this->sunCost = 100;
    this->cooldown = 2;
    this->range = 5;
    this->damage = 10;

    this->detectorBox = new PlantDetectorColliderBox();
    this->AddChildren(this->detectorBox);

    this->hitbox = new PlantColliderBox();
    this->AddChildren(this->hitbox);

    this->idleSpriteRect = new SpriteRect();
    Texture* idleTexture = new Texture("asset/plants/peashooter/peashooter_sheet.png");
    this->idleSpriteRect->SetTexture(idleTexture, Vector2(8, 8), 60);
    this->idleSpriteRect->animationTime = this->cooldown;
    this->AddChildren(this->idleSpriteRect);

    this->attackSpriteRect = new SpriteRect();
    Texture* attackTexture = new Texture("asset/plants/peashooter/peashooter_attack.png");
    this->attackSpriteRect->SetTexture(attackTexture, Vector2(8, 8), 60);
    this->attackSpriteRect->animationTime = this->cooldown;
    this->AddChildren(this->attackSpriteRect);

}

PeaShooter::~PeaShooter() {

}

BasePlant* PeaShooter::Create() {
    PeaShooter* pea = new PeaShooter();
    pea->isAttack = true;
    return pea;
}

void PeaShooter::SetSize(const Vector2& size) {
    BasePlant::SetSize(size);
    this->hitbox->size = size;
    this->detectorBox->size = Vector2(size.x * this->range, size.y);
    this->idleSpriteRect->size = size;
    this->attackSpriteRect->size = size;

}

Vector2 PeaShooter::GetSize() {
    return this->size;
}

Texture* PeaShooter::GetIcon() {
    return new Texture("asset/plants/peashooter/Peashooter.png");
}

void PeaShooter::Update(float delta) {
    BasePlant::Update(delta);
    this->isAttack = this->detectorBox->hasZombie;
    this->idleSpriteRect->isVisible = !this->isAttack;
    this->attackSpriteRect->isVisible = this->isAttack;

    this->time += delta;
    if (this->isAttack) {
        if(this->time > this->cooldown) {
            this->time = 0;
            PeaBullet* bullet = new PeaBullet();
            bullet->velocity = Vector2(100, 0);
            bullet->damage = this->damage;
            bullet->SetSize(Vector2(50, 50));
            this->AddChildren(bullet);
        }
    }
}