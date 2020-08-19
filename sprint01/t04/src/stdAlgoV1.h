#pragma once

#include <iostream>
#include <fstream>
#include <forward_list>
#include <string>
#include <algorithm>

struct Statistic {
  int size = 0;
  bool isRich = false;
  bool isNotFifteenLength = true;
  bool velEnd = true;
  int melCount = 0;;
};

void stdAlgoV1(std::forward_list<std::string> names);
