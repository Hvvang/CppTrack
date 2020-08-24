#pragma once
#include <iostream>

class Creature {
public:
    Creature() {
        std::cout << "Creature was created" << '\n';
    }
    ~Creature() {
        std::cout << "Creature was deleted" << '\n';
    }
};

class Wolf : public virtual Creature {
public:
    Wolf() = default;
    ~Wolf() = default;
};

class Human : public virtual Creature {
public:
    Human() = default;
    ~Human() = default;
};

class Werewolf : Wolf, Human {
public:
    Werewolf() {
        std::cout << "Werewolf was created" << '\n';
    }
    ~Werewolf() {
        std::cout << "Werewolf was deleted" << '\n';
    }
};
