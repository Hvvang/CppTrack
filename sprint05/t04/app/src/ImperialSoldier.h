#pragma once

#include "Soldier.h"

class Soldier;
class ImperialSoldier final: public Soldier {
public:
    ImperialSoldier() : Soldier{"Martin", 100} {
        std::cout << "Imperial soldier was created" << '\n';
    }
    ~ImperialSoldier() {
        std::cout << "Imperial soldier was deleted" << '\n';
    }
};
