#include "Redguard.h"

Redguard::Redguard(std::string&& name) :
    Creature(std::move(name)){
    Redguard::sayPhrase();
}

void Redguard::sayPhrase() const {
    std::cout << "I am " << this->getName() << " from Redguards, wanna trade?" << '\n';
}
