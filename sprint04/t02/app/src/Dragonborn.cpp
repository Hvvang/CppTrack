#include "Dragonborn.h"
#include <iostream>
#include <map>

void Dragonborn::executeAction(const Actions action) {
    const std::map<Actions, void (Dragonborn::*)() const> map = {
        { Actions::Shout, &Dragonborn::shoutThuum },
        { Actions::Magic, &Dragonborn::attackWithMagic },
        { Actions::Weapon, &Dragonborn::attackWithWeapon }
    };
    std::__invoke(map.at(action), this);
}

void Dragonborn::shoutThuum() const {
    std::cout << "Yol Toor Shul" << '\n';
}

void Dragonborn::attackWithMagic() const {
    std::cout << "*attacks with magic spell*" << '\n';
}

void Dragonborn::attackWithWeapon() const {
    std::cout << "*attacks with weapon*" << '\n';
}
