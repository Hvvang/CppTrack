#include "ImperialSoldier.h"
#include <iostream>

ImperialSoldier::ImperialSoldier() {
    m_health = 100;
}

ImperialSoldier::~ImperialSoldier() {
    delete m_weapon;
}

void ImperialSoldier::setWeapon(Sword *sword) {
    m_weapon = sword;
}

void ImperialSoldier::attack(StormcloakSoldier &enemy) {
    int damage = m_weapon->getDamage();

    std::cout << "Imperial soldier attacks and deals " << damage << " damage" << '\n';
    enemy.consumeDamage(damage);
}

void ImperialSoldier::consumeDamage(int amount) {
    m_health -= amount;
    std::cout << "Imperial soldier consumes " << amount << " of damage" << '\n';
}

int ImperialSoldier::getHealth() const {
    return m_health;
}
