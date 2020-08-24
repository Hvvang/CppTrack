#pragma once

#include "ImperialSoldier.h"
#include "Axe.h"
// #include "Sword.h"

class ImperialSoldier;

class StormcloakSoldier final {
public:
    StormcloakSoldier();
    ~StormcloakSoldier();

    void setWeapon(Axe* axe);
    void attack(ImperialSoldier& enemy);
    void consumeDamage(int amount);
    int getHealth() const;

private:
    Axe* m_weapon;
    int m_health;
};
