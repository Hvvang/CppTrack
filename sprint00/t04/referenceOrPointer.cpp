#include "referenceOrPointer.h"

void multiplyByPointer(int* ptr, int mult) {
  *ptr = *ptr * mult;
}
void multiplyByReference(int& ref, int mult) {
  ref = ref * mult;
}
