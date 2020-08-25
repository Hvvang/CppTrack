#include <iostream>
#include <string>
#include "src/ImperialSoldier.h"
#include "src/StormcloakSoldier.h"
#include "src/Axe.h"
#include "src/Sword.h"

template <typename T>
bool IsInRange(const T& val, const T& from, const T& to) {
    if (val > to || val < from) {
        return false;
    } else return true;
}

bool argsValidator(char **argv, int& swordDmg, int& axeDmg) {
    auto index = 0ul;

    swordDmg = stoi(std::string(argv[1]), &index);
    if (argv[1][index] != '\0') {
        throw false;
    }
    axeDmg = stoi(std::string(argv[2]), &index);
    if (argv[2][index] != '\0') {
        throw false;
    }
    if (!IsInRange(swordDmg, 10, 20) || !IsInRange(axeDmg, 10, 20)) {
        throw false;
    }
    return true;
}

ImperialSoldier initImperial(const int& swordDmg) {
    ImperialSoldier imperialSoldier("Martin", 100);
    Sword *sword = new Sword(swordDmg);

    imperialSoldier.setWeapon(sword);
    return imperialSoldier;
}

StormcloakSoldier initStormcloak(const int& axeDmg) {
    StormcloakSoldier stormcloakSoldier("Flynn", 100);
    Axe *axe = new Axe(axeDmg);

    stormcloakSoldier.setWeapon(axe);
    return stormcloakSoldier;
}


int main(int argc, char** argv) {
    if (argc == 3) {
        try {
            int swordDmg = 0;
            int axeDmg = 0;
            argsValidator(argv, swordDmg, axeDmg);

            ImperialSoldier imperialSoldier = initImperial(swordDmg);
            StormcloakSoldier stormcloakSoldier = initStormcloak(axeDmg);

            std::cout << "\n" << "***The battle has begun!***" << "\n\n";
            while (true) {
                stormcloakSoldier.attack(imperialSoldier);
                if (imperialSoldier.getHealth() < 0) {
                    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << '\n';
                    std::cout << "Stormcloack has won!" << '\n';
                    break;
                }
                imperialSoldier.attack(stormcloakSoldier);
                if (stormcloakSoldier.getHealth() < 0) {
                    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << '\n';
                    std::cout << "Imperial has won!" << '\n';
                    break;
                }
                std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << '\n';
            }
            std::cout << '\n';
        }
        catch(...) {
            std::cerr << "Damage has to bein a range of 10-20 points." << '\n';
        }
    } else {
        std::cerr << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]" << '\n';
    }
    return 0;
}
