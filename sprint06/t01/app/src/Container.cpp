#include "Container.h"

Container::Container(bool isLocked, const LockpickDifficulty difficulty) {
    m_isLocked = isLocked;
    m_difficulty = difficulty;
}

bool Container::isLocked() const {
    return m_isLocked;
}

LockpickDifficulty Container::lockDifficulty() const {
    return m_difficulty;
}

bool Container::tryToOpen(LockpickDifficulty skill) {
    if (skill < m_difficulty && m_isLocked) {
        return false;
    } else {
        m_isLocked = true;
        return true;
    }
}
