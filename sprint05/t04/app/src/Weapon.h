/* Weapon.h */
#pragma once

class Weapon {
public:
    explicit Weapon(int damage);
    virtual ~Weapon() = default;
    int getDamage() const;

private:
    const int m_damage;
};
