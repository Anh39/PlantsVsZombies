#include "peaBullet.h"
using namespace std;
PeaBullet::PeaBullet() {
    this->velocity = Vector2(50, 0);

    this->colorRect = new ColorRect();
    this->colorRect->color = Color(0, 255, 127);
    this->AddChildren(this->colorRect);

    this->collider = new PeaBulletCollider();
    this->collider->collideMask = CollideLayer1;
    this->AddChildren(this->collider);

    this->Name = "PeaBullet";
}
void PeaBullet::SetSize(const Vector2& size) {
    this->colorRect->size = size;
    this->collider->size = size;
}
PeaBullet::~PeaBullet() {

}
void PeaBullet::Update(float delta) {
    this->position += this->velocity * delta;
}
