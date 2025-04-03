#pragma once
#include "engine.h"

using namespace std;

class BaseZombie: public Node
{
public:
    BaseZombie();
    ~BaseZombie();
    void SetSize(const Vector2& size);

    virtual BaseZombie* Copy();
protected:
    CollideNode* collider;
    ColorRect* colorRect;
};