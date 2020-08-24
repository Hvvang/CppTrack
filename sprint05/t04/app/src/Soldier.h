/* Soldier.h */
#pragma once
#include <iostream>
#include "Weapon.h"

class Weapon;
class Soldier {
public:
    Soldier(std::string&& name, int health);
    virtual ~Soldier();
    void attack(Soldier& other);
    void consumeDamage(int amount);
    void setWeapon(Weapon* weapon);
    int getHealth() const;
    std::string getName() const;

private:
    Weapon* m_weapon;
    std::string m_name;
    int m_health;
};
