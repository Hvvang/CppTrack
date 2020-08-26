#include "Imperial.h"

Imperial::Imperial(std::string&& name) :
    Creature(std::move(name)) {
    Imperial::sayPhrase();
}

void Imperial::sayPhrase() const {
    std::cout << "I am " << this->getName() << ", Imperial soldier! Stop right here!" << '\n';
}
