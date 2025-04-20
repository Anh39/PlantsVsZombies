#include "level1.h"
#include "../Plants/include.h"
#include "../Zombies/include.h"
using namespace std;

ZombieWave GetWave() {
    ZombieWave wave1 = ZombieWave();
    // 5s
    vector<ZombieWithLane> z1 = {
        {0, new NormalZombie()},
        {1, new NormalZombie()}
    };
    ZombiesWithTime t1 = ZombiesWithTime(5, z1);
    // 7s
    vector<ZombieWithLane> z2 = {
        {1, new NormalZombie()},
        {3, new NormalZombie()}
    };
    ZombiesWithTime t2 = ZombiesWithTime(7, z2);
    // 9s
    vector<ZombieWithLane> z3 = {
        {1, new NormalZombie()},
        {4, new NormalZombie()}
    };
    ZombiesWithTime t3 = ZombiesWithTime(9, z3);


    wave1.zombies.push_back(t1);
    wave1.zombies.push_back(t2);
    wave1.zombies.push_back(t3);
    return wave1;
}

Level* GenerateLevel1() {
    Level* level = new Level();
    
    level->plants.push_back(new PeaShooter());
    level->plants.push_back(new PeaShooter());




    level->zombieWaves.push_back(GetWave());

    level->zombieWaves.push_back(GetWave());

    level->zombieWaves.push_back(GetWave());


    return level;
}