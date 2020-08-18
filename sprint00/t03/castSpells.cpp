#include "castSpells.h"

int* castToNonConstIntPtr(const int* ptr) {
  int *res = const_cast<int*>(ptr);

  return res;
}

int castFloatToInt(float number) {
  int res = static_cast<int>(number);

  return res;
}
