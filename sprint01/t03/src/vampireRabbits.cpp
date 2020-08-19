#include "vampireRabbits.h"

Rabbit createRabbit(void) {
    Rabbit rabbit;

    rabbit.gender = (rand() % 100 >= 50) ? Gender::Female : Gender::Male;
    rabbit.isVampire = (rand() % 100 == 1) ? true : false;
    rabbit.age = 0;
    return rabbit;
}

void incrementAge(Population& population) {
    for (auto& rabbit : population.vampires) {
        rabbit.age++;
    }
    for (auto& rabbit : population.male) {
        rabbit.age++;
    }
    for (auto& rabbit : population.female) {
        rabbit.age++;
    }
}

void killRabbits(Population& population) {
    for (auto itr = population.vampires.begin();
             itr != population.vampires.end(); itr++) {
        if ((*itr).age == 9) {
            population.vampires.erase(itr);
            population.size--;
        }
    }
    for (auto itr = population.male.begin();
             itr != population.male.end(); itr++) {
        if ((*itr).age == 4) {
            population.male.erase(itr);
            population.size--;
        }
    }
    for (auto itr = population.female.begin();
             itr != population.female.end(); itr++) {
        if ((*itr).age == 4) {
            population.female.erase(itr);
            population.size--;
        }
    }
}

void vampireRabbitsIncrement(Population& population) {
    int vampiresCount = population.vampires.size();

    while (vampiresCount--) {
        srand(time(0));
        if (rand() % 2 == 1) {
            if (population.female.size() > 0) {
                population.vampires.push_back(population.female.front());
                population.female.pop_front();
            }
        } else {
            if (population.male.size() > 0) {
                population.vampires.push_back(population.male.front());
                population.male.pop_front();
            }
        }
    }
}

int countPairs(const std::list<Rabbit>& male,
               const std::list<Rabbit>& female) {
    int males = male.size();
    int females = female.size();

    return std::min(males, females);
}

void reproduction(const int& pairs, Population& population) {
    for (int i = 0; i < pairs; i++) {
        Rabbit rabbit = createRabbit();

        population.size++;
        if (rabbit.isVampire) {
            population.vampires.push_back(rabbit);
        } else {
            rabbit.gender == Gender::Female ?
                             population.female.push_back(rabbit) :
                             population.male.push_back(rabbit);
        }
    }
}

void vampireRabbits() {
    Population population;

    srand(time(NULL));
    reproduction(10, population);
    while (population.size < 1000 && population.size > 0) {
        std::cout << "Males: " << population.male.size() << std::endl;
        std::cout << "Females: " << population.female.size() << std::endl;
        std::cout << "Vampires: " << population.vampires.size() << std::endl;
        std::cout << std::endl;
        sleep(1);
        incrementAge(population);
        killRabbits(population);
        int pairs = countPairs(population.male, population.female);
        reproduction(pairs, population);
        vampireRabbitsIncrement(population);
    }
}
