#include "level1.h"
#include "../Plants/include.h"
#include "../Zombies/include.h"
using namespace std;

ZombieWave GetWave() {
    ZombieWave wave = ZombieWave();
    // 5s
    vector<ZombieWithLane> z1 = {
        {2, new NormalZombie()},
    };
    ZombiesWithTime t1 = ZombiesWithTime(5, z1);
    // 7s
    vector<ZombieWithLane> z2 = {
        {2, new NormalZombie()},
        {3, new NormalZombie()}
    };
    ZombiesWithTime t2 = ZombiesWithTime(10, z2);
    // 9s
    vector<ZombieWithLane> z3 = {
        {2, new NormalZombie()},
        {4, new NormalZombie()},
        {1, new NormalZombie()}
    };
    ZombiesWithTime t3 = ZombiesWithTime(15, z3);

    wave.zombies.push_back(t1);
    wave.zombies.push_back(t2);
    wave.zombies.push_back(t3);
    return wave;
}

Level* GenerateLevel1() {
    Level* level = new Level();
    
    level->plants.push_back(new PeaShooter());
    level->zombieWaves.push_back(GetWave());
    return level;
}