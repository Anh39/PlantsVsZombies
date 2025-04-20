#include "normalZombie.h"

NormalZombie::NormalZombie() {
    this->speed = 50;
    this->heathPoint = 100;
    this->damage = 10;
    this->cooldown = 2;
    this->time = this->cooldown;

    this->walkingSpriteRect = new SpriteRect();
    Texture* walkingTexture = new Texture("asset/zombies/Normal/ZombieWalk1.png");
    this->walkingSpriteRect->SetTexture(walkingTexture, Vector2(8, 6), 46);
    this->walkingSpriteRect->animationTime = 2;
    this->AddChildren(this->walkingSpriteRect);

    this->attackSpriteRect = new SpriteRect();
    Texture* attackTexture = new Texture("asset/zombies/Normal/ZombieAttack.png");
    this->attackSpriteRect->SetTexture(attackTexture, Vector2(8, 5), 39);
    this->attackSpriteRect->animationTime = this->cooldown;
    this->AddChildren(this->attackSpriteRect);

    this->dieSpriteRect = new SpriteRect();
    Texture* dieTexture = new Texture("asset/zombies/Normal/Zombie_die1.png");
    this->dieSpriteRect->SetTexture(dieTexture, Vector2(8, 5), 33);
    this->dieSpriteRect->animationTime = 2;
    this->AddChildren(this->dieSpriteRect);

    this->detectorBox->OnCollidedWithPlant = [this](BasePlant* plant) {
        this->time += this->relayDelta;
        //std::cout << this->time << "|" << this->cooldown << "|" << plant->heathPoint << "|" << this->damage << std::endl;
        if (this->time >= this->cooldown) {
            this->time = 0;
            plant->heathPoint -= this->damage;
        }
    };
}

NormalZombie::~NormalZombie() {

}

void NormalZombie::SetSize(const Vector2& size) {
    BaseZombie::SetSize(size);
    this->walkingSpriteRect->size = size;
    this->attackSpriteRect->size = size;
}

void NormalZombie::Update(float delta) {
    this->relayDelta = delta;
    BaseZombie::Update(delta);
    this->isAttack = this->detectorBox->hasPlant;
    if (!this->isAttack) {
        this->walkingSpriteRect->isVisible = true;
        this->attackSpriteRect->isVisible = false;
        this->position.x -= this->speed * delta;

    } else {
        this->walkingSpriteRect->isVisible = false;
        this->attackSpriteRect->isVisible = true;

    }

}