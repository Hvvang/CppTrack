#pragma once

#include "Soldier.h"

class Soldier;
class ImperialSoldier final: public Soldier {
public:
    ImperialSoldier(std::string&& name, int health);
    ~ImperialSoldier();
};
