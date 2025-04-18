#pragma once

#include "engine.h"

#include <vector>

class BaseZombie: public Node
{
public:
    BaseZombie();
    ~BaseZombie();
};
class BasePlant: public Node 
{
public:
    BasePlant();
    ~BasePlant();
    
    virtual BasePlant* Create();
    virtual void SetSize(const Vector2& size);
    virtual Vector2 GetSize();
    virtual Texture* GetIcon();
};
class Level
{
public:
    Level();
    ~Level();

    std::vector<BasePlant*> plants;
    std::vector<BaseZombie*> zombies;
};