#include "level.h"
using namespace std;


Level::Level() {
    this->plants = vector<BasePlant*>();
    this->zombieWaves = vector<ZombieWave>();
}

Level::~Level() {

}

