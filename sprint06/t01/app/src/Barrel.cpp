#include "Barrel.h"

Barrel::Barrel() :
    Container(false, LockpickDifficulty::None) { }

std::string Barrel::name() const {
    return "Barrel";
}
