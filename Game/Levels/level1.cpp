#include "level1.h"
#include "../Testplant/starfruit.h"

Level* GenerateLevel1() {
    Level* level = new Level();
    
    level->plants.push_back(new TestPlant());
    level->plants.push_back(new TestPlant());

    return level;
}