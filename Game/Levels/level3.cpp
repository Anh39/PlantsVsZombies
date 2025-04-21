#include "level3.h"
#include "level2.h"
#include "../Plants/include.h"
#include "../Zombies/include.h"
using namespace std;

ZombieWave GetWave3() {
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
    // 9s
    vector<ZombieWithLane> z4 = {
        {2, new NormalZombie()},
        {4, new NormalZombie()},
        {1, new NormalZombie()},
        {2, new NormalZombie()},
        {0, new NormalZombie()},
        {3, new NormalZombie()}
    };
    ZombiesWithTime t4 = ZombiesWithTime(30, z4);

    // 9s
    vector<ZombieWithLane> z5 = {
        {2, new NormalZombie()},
        {4, new NormalZombie()},
        {1, new NormalZombie()},
        {2, new NormalZombie()},
        {0, new NormalZombie()},
        {3, new NormalZombie()},
        {2, new NormalZombie()},
        {4, new NormalZombie()},
        {1, new NormalZombie()},
        {2, new NormalZombie()},
        {0, new NormalZombie()},
        {3, new NormalZombie()},
    };
    ZombiesWithTime t5 = ZombiesWithTime(50, z5);

    wave.zombies.push_back(t1);
    wave.zombies.push_back(t2);
    wave.zombies.push_back(t3);
    wave.zombies.push_back(t4);
    wave.zombies.push_back(t5);


    return wave;
}

Level* GenerateLevel3() {
    Level* level = new Level();
    
    level->plants.push_back(new Sunflower());
    level->plants.push_back(new PeaShooter());
    level->plants.push_back(new Wallnut());




    level->zombieWaves.push_back(GetWave1());
    level->zombieWaves.push_back(GetWave2());
    level->zombieWaves.push_back(GetWave3());


    return level;
}