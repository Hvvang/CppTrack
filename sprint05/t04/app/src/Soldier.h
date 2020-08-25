/* Soldier.h */
#pragma once
#include <iostream>
#include "Weapon.h"

class Weapon;
class Soldier {
public:
    Soldier(std::string&& name, int health = 100);
    virtual ~Soldier();
    void attack(Soldier& other);
    void setWeapon(Weapon* weapon);
    int getHealth() const;

private:
    Weapon* m_weapon;
    std::string m_name;
    int m_health;
};
