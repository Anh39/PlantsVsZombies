#include "peaBullet.h"

PeaBullet::PeaBullet() {
    this->size = Vector2(0, 0);


    this->bulletTextureRect = new TextureRect();
    this->bulletTextureRect->texture = new Texture("asset/plants/bullets/pea.png");
    this->AddChildren(this->bulletTextureRect);


    this->colliderBox = new BulletColliderBox();
    this->AddChildren(this->colliderBox);
    this->colliderBox->OnCollideWithZombie = [this](BaseZombie* zombie) {
        if (!this->isDeleted) {
            zombie->heathPoint -= this->damage;
            this->Delete();
        }
    };


}

PeaBullet::~PeaBullet() {

}

void PeaBullet::Update(float delta) {
    this->position += this->velocity * delta;    
}


void PeaBullet::SetSize(const Vector2& size) {
    this->size = size;
    this->bulletTextureRect->size = size;
    this->colliderBox->size = size;
}

Vector2 PeaBullet::GetSize() {
    return this->size;
}
