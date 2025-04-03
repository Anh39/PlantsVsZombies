#pragma once
#include "engine.h"

class PeaBulletCollider: public CollideNode 
{
public:
    PeaBulletCollider();
    ~PeaBulletCollider();
    void OnCollide(CollideNode* other) override;
};