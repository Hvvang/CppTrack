#include "StormcloakSoldier.h"

StormcloakSoldier::StormcloakSoldier(std::string&& name, int health) :
    Soldier(std::move(name), health) {
    std::cout << "Stormcloak soldier was created" << '\n';
}
StormcloakSoldier::~StormcloakSoldier() {
    std::cout << "Stormcloak soldier was deleted" << '\n';
}
