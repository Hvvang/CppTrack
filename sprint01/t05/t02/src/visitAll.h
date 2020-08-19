#pragma once

#include <deque>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

struct Info {
  std::string name;
  int stamina;
  int distance;
};

bool parser(std::deque<Info>& data, int argc, char** argv);
int bestRoute(const std::deque<Info>& data);
