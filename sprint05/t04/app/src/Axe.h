#pragma once

#include "Weapon.h"

class Weapon;
class Axe final: public Weapon {
public:
    explicit Axe(int damage);
};
