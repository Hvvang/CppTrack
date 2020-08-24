#include "Draugr.h"

Draugr::Draugr() : Draugr(100, 50) { }

Draugr::Draugr(int frostResist) : Draugr(100, frostResist) { }

Draugr::Draugr(Draugr& other) : Draugr(other.m_health, other.m_frostResist) {
    std::cout << "Copy constructor was called" << '\n';
}

Draugr::Draugr(Draugr&& other) : Draugr(other.m_health, other.m_frostResist)  {
    std::cout << "Move constructor was called" << '\n';
}

void Draugr::setName(const std::string&& name) {
    m_name = name;
}

Draugr::Draugr(double health, int frostResist) :
    m_frostResist(frostResist),
    m_health(health) {
    std::cout << "Draugr with " << m_health << " health and " << m_frostResist
              << "% frost resist was born" << "\n";
}

void Draugr::shoutPhrase(int shoutNumber) const {
    if (shoutNumber >= 0 && shoutNumber <= 8) {
        std::cout << "Draugr " << m_name << " (" << m_health << " health, " << m_frostResist
                  << "% frost resist) shouts:" << '\n';
    }
    switch (shoutNumber) {
        case 0 :
            std::cout << "Qiilaan Us Dilon!" << '\n';
            break;
        case 1 :
            std::cout << "Bolog Aaz, Mal Lir!" << '\n';
            break;
        case 2 :
            std::cout << "Kren Sosaal!" << '\n';
            break;
        case 3 :
            std::cout << "Dir Volaan!" << '\n';
            break;
        case 4 :
            std::cout << "Aar Vin Ok!" << '\n';
            break;
        case 5 :
            std::cout << "Unslaad Krosis!" << '\n';
            break;
        case 6 :
            std::cout << "Faaz! Paak! Dinok!" << '\n';
            break;
        case 7 :
            std::cout << "Aav Dilon!" << '\n';
            break;
        case 8 :
            std::cout << "Sovngarde Saraan!" << '\n';
            break;
        default :
            std::cerr << "Invalid shoutNumber" << '\n';
    }
}
