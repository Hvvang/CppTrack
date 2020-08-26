#include <iostream>
#include <string>
#include "src/ISpell.h"
#include "src/Creature.h"
#include "src/Redguard.h"
#include "src/Imperial.h"
#include "src/Equilibrium.h"
#include "src/Fireball.h"
#include "src/Flames.h"
#include "src/Freeze.h"
#include "src/Healing.h"

int main(int argc, char** argv) {
    Redguard redguard("Jojo");
    Imperial imperial("Dio");

    std::cout << redguard << std::endl;
    std::cout << imperial << std::endl;
    Spells::ISpell* healing = new Healing;
    Spells::ISpell* fireball = new Fireball;
    Spells::ISpell* equilibrium = new Equilibrium;
    Spells::ISpell* flames = new Flames;
    Spells::ISpell* freeze = new Freeze;

    redguard.learnSpell(healing);
    redguard.learnSpell(fireball);
    imperial.learnSpell(equilibrium);
    imperial.learnSpell(equilibrium);

    redguard.castSpell(fireball->getType(), imperial);
    imperial.castSpell(equilibrium->getType(), redguard);

    std::cout << redguard << std::endl;
    std::cout << imperial << std::endl;

    imperial.castSpell(flames->getType(), redguard);
    imperial.learnSpell(flames);
    imperial.learnSpell(freeze);

    redguard.castSpell(healing->getType(), redguard);
    imperial.castSpell(freeze->getType(), redguard);

    std::cout << redguard << std::endl;
    std::cout << imperial << std::endl;

    redguard.castSpell(fireball->getType(), imperial);
    redguard.castSpell(fireball->getType(), imperial);
    redguard.castSpell(fireball->getType(), imperial);

    std::cout << redguard << std::endl;
    std::cout << imperial << std::endl;
    return 0;
}
