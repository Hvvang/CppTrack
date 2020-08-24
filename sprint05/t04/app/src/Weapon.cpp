#include "Weapon.h"

Weapon::Weapon(int damage) :
    m_damage(damage) {

}

int Weapon::getDamage() const {
    return m_damage;
}
