#pragma once

#include "Soldier.h"

class Soldier;
class StormcloakSoldier final: public Soldier {
public:
    StormcloakSoldier() : Soldier("Flynn", 100) {
        std::cout << "Stormcloak soldier was created" << '\n';
    }
    ~StormcloakSoldier() {
        std::cout << "Stormcloak soldier was deleted" << '\n';
    }
};
