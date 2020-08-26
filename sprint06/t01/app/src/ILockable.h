/* ILockable.h */
#pragma once

#include "LockpickDifficulty.h"

class ILockable {
public:
    LockpickDifficulty lockDifficulty() const;
    bool isLocked();
private:

};
