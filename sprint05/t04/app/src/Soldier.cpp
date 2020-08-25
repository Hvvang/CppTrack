#include "Soldier.h"


Soldier::Soldier(std::string&& name, int health) {
    m_name = name;
    m_health = health;
    std::cout << "Soldier " << name << " was created" << '\n';
}

Soldier::~Soldier() {
    std::cout << "Soldier " << m_name << " was deleted" << '\n';
    delete m_weapon;
}

int Soldier::getHealth() const {
    return m_health;
}

void Soldier::setWeapon(Weapon* weapon) {
    m_weapon = weapon;
}

void Soldier::attack(Soldier& other) {
    int damage = m_weapon->getDamage();

    std::cout << m_name << " attacks " << other.m_name << " and deals " << damage << " damage" << '\n';
    other.m_health -= damage;
}
