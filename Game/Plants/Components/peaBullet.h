#pragma once

#include "engine.h"
#include "bulletCollider.h"

class BulletColliderBox;
class PeaBullet: public Node
{
public:
    Vector2 velocity;
    float damage;
    PeaBullet();
    ~PeaBullet();

    void SetSize(const Vector2& size);
    Vector2 GetSize();
    void Update(float delta) override;
private:
    Vector2 size;
    BulletColliderBox* colliderBox;
    TextureRect* bulletTextureRect;

};