#pragma once

#include "engine.h"

#include <vector>

class BaseZombie: public Node
{
public:
    float speed;

    BaseZombie();
    ~BaseZombie();
    
    virtual void SetSize(const Vector2& size);
    virtual Vector2 GetSize();
};

class BasePlant: public Node 
{
public:
    float sunCost;
    float cardCooldown;
    float heathPoint;
    float cooldown;
    float time;

    BasePlant();
    ~BasePlant();
    
    virtual BasePlant* Create();
    virtual void SetSize(const Vector2& size);
    virtual Vector2 GetSize();
    virtual Texture* GetIcon();

};
class ZombieWithLane
{
public:
    BaseZombie* zombie;
    int lane;
    ZombieWithLane(int lane, BaseZombie* zombie) {
        this->zombie = zombie;
        this->lane = lane;
    }
};
class ZombiesWithTime
{
public:
    std::vector<ZombieWithLane> zombies;
    float spawnTime;
    ZombiesWithTime(float spawnTime, std::vector<ZombieWithLane> zombies) {
        this->spawnTime = spawnTime;
        this->zombies = zombies;
    }
};
class ZombieWave 
{
public:
    ZombieWave() {};
    ~ZombieWave() {};

    std::vector<ZombiesWithTime> zombies;
};
class Level
{
public:
    Level();
    ~Level();

    std::vector<BasePlant*> plants;
    std::vector<ZombieWave> zombieWaves;
};