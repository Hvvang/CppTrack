#pragma once

#include "Container.h"

class Chest final : public Container {
public:
    Chest(bool isLocked, const LockpickDifficulty difficulty);
    std::string name() const override;
};
