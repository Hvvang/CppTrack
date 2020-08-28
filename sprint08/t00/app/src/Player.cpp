#include "Player.h"
// #include "Map.h"
// #include "MoveManager.h"

void Player::movePlayer(MoveManager::Direction dir) {
    switch (dir) {
        case MoveManager::Direction::Up: m_posY -= 1;
            break;
        case MoveManager::Direction::Down: m_posY += 1;
            break;
        case MoveManager::Direction::Left: m_posX -= 1;
            break;
        case MoveManager::Direction::Right: m_posX += 1;
            break;
    }
}
char Player::getIdentifier() const {
    return 'P';
}
size_t Player::posX() const {
    return m_posX;
}
size_t Player::posY() const {
    return m_posY;
}
