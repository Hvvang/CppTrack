/* IOpenable.h */
#pragma once

#include "LockpickDifficulty.h"

class IOpenable {
public:
    bool tryToOpen(LockpickDifficulty skill);
private:
};
