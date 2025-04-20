#pragma once

#include "engine.h"
#include "Zombies/baseZombie.h"
#include "Plants/basePlant.h"

#include <vector>
class WinEvent: public Event
{
public:
    WinEvent() {};
    ~WinEvent() {};
};
class LoseEvent: public Event
{
public:
    LoseEvent() {};
    ~LoseEvent() {};
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