#pragma once

class Axe final {
public:
    Axe(int damage) : m_damage(damage) {};
    int getDamage() const;

private:
    const int m_damage;
};
