#pragma once

#include <list>
#include <iostream>
#include <string>
#include <random>
#include <unistd.h>
#include <ctime>

enum class Gender {
  Male,
  Female
};

struct Rabbit {
  Gender gender;
  bool isVampire;
  int age;
};

struct Population {
  std::list<Rabbit> vampires;
  std::list<Rabbit> male;
  std::list<Rabbit> female;
  int size;
};

void vampireRabbits();
