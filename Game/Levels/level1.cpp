#include "level1.h"
#include "../Plants/testPlant.h"
#include "../Zombies/testZombie.h"
using namespace std;

ZombieWave GetWave() {
    ZombieWave wave1 = ZombieWave();
    // 5s
    vector<ZombieWithLane> z1 = {
        {0, new TestZombie()},
        {1, new TestZombie()}
    };
    ZombiesWithTime t1 = ZombiesWithTime(5, z1);
    // 7s
    vector<ZombieWithLane> z2 = {
        {1, new TestZombie()},
        {3, new TestZombie()}
    };
    ZombiesWithTime t2 = ZombiesWithTime(7, z2);
    // 9s
    vector<ZombieWithLane> z3 = {
        {1, new TestZombie()},
        {4, new TestZombie()}
    };
    ZombiesWithTime t3 = ZombiesWithTime(9, z3);


    wave1.zombies.push_back(t1);
    wave1.zombies.push_back(t2);
    wave1.zombies.push_back(t3);
    return wave1;
}

Level* GenerateLevel1() {
    Level* level = new Level();
    
    level->plants.push_back(new TestPlant());
    level->plants.push_back(new TestPlant());




    level->zombieWaves.push_back(GetWave());

    level->zombieWaves.push_back(GetWave());

    level->zombieWaves.push_back(GetWave());


    return level;
}