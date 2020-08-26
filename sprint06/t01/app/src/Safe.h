#pragma once

#include "Container.h"

class Safe final : public Container {
public:
    Safe(bool isLocked, const LockpickDifficulty difficulty);
    std::string name() const override;
};
