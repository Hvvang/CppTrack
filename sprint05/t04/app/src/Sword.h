#pragma once

#include "Weapon.h"

class Weapon;
class Sword final: public Weapon {
public:
    explicit Sword(int damage);
};
