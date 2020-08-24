#include "Draugr.h"

Draugr::Draugr() :
    m_frostResist(50) {
    m_health = 100;
}

void Draugr::shoutPhrase(int shoutNumber) const {
    if (shoutNumber >= 0 && shoutNumber <= 8) {
        std::cout << "Draugr (100 health, 50% frost resist) shouts:" << '\n';
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
