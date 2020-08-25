#pragma once

#include "Soldier.h"

class Soldier;
class StormcloakSoldier final: public Soldier {
public:
    StormcloakSoldier(std::string&& name, int health);
    ~StormcloakSoldier();
};
