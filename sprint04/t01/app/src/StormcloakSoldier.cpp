#include "StormcloakSoldier.h"
#include <iostream>

StormcloakSoldier::StormcloakSoldier() {
    m_health = 100;
}

StormcloakSoldier::~StormcloakSoldier() {
    delete m_weapon;
}

void StormcloakSoldier::setWeapon(Axe* axe) {
    m_weapon = axe;
}

void StormcloakSoldier::attack(ImperialSoldier &enemy) {
    int damage = m_weapon->getDamage();

    std::cout << "Stormcloak soldier attacks and deals " << damage << " damage" << '\n';
    enemy.consumeDamage(damage);
}

void StormcloakSoldier::consumeDamage(int amount) {
    m_health -= amount;
    std::cout << "Stormcloak soldier consumes " <<
                  amount << " of damage" << '\n';
}

int StormcloakSoldier::getHealth() const {
    return m_health;
}
