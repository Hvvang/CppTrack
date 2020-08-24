#pragma once

#include <iostream>

class Draugr {
public:
    Draugr();
    explicit Draugr(int frostResist);
    explicit Draugr(double health, int frostResist = 50);
    void shoutPhrase(int shoutNumber) const;

private:
    double m_health;
    const int m_frostResist;
};
