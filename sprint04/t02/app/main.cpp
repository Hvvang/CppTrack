#include <iostream>
#include <string>
#include "src/Dragonborn.h"

template <class Collection, class T>
auto Find(Collection& c, const T& value) {
    for (auto iter = c.begin(); iter != c.end(); iter++) {
        if (*iter == value) {
            return iter;
        }
    }
    return c.end();
}

int main(int argc, char** argv) {
    if (argc == 2) {
        Dragonborn dragonborn;
        std::map<std::string, Dragonborn::Actions> map = {
            {std::string("shout"), Dragonborn::Actions::Shout},
            {std::string("magic"), Dragonborn::Actions::Magic},
            {std::string("weapon"), Dragonborn::Actions::Weapon}
        };

        if (map.find(std::string(argv[1])) != map.end()) {
            dragonborn.executeAction(map[argv[1]]);
        } else {
            std::cerr << "Invalid action" << '\n';
        }
    } else {
        std::cerr << "usage: ./dragonborn [action]" << '\n';
    }
    return 0;
}
