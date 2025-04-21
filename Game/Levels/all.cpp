#include "all.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"

Level* GenerateLevel(std::string name) {
    std::cout << "Load level: " << name << std::endl;
    if (name == "1") {
        return GenerateLevel1();
    } 
    else if (name == "2") {
        return GenerateLevel2();
    }
    else {
        return GenerateLevel3();
    }
}