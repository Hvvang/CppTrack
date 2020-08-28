#pragma once

#include "MoveManager.h"

/* Player.h */
class Player final {
public:
    Player() = default;
    ~Player() = default;

    void movePlayer(MoveManager::Direction dir);
    char getIdentifier() const;
    size_t posX() const;
    size_t posY() const;

private:
    size_t m_posX {0};
    size_t m_posY {0};
};
