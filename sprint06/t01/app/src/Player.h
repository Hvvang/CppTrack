/* Player.h */
#pragma once

#include "Container.h"
#include <iostream>

class Player final {
public:
    explicit Player(const std::string& name);
    void openContainer(Container* container);
    void setLockpickSkill(LockpickDifficulty skill);

private:
    LockpickDifficulty m_lockpickSkill { LockpickDifficulty::None };
    std::string m_name;
};
