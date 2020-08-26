#include "Safe.h"

Safe::Safe(bool isLocked, const LockpickDifficulty difficulty) :
    Container(isLocked, difficulty) { }

std::string Safe::name() const {
    return "Safe";
}
