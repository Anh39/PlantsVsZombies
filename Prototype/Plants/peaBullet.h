#pragma once
#include "engine.h"
#include "peaBulletCollider.h"

class PeaBullet: public Node
{
public:
    Vector2 velocity;
    void SetSize(const Vector2& other);
    PeaBullet();
    ~PeaBullet();
    void Update(float delta) override;
private:
    PeaBulletCollider* collider;
    ColorRect* colorRect;
};

