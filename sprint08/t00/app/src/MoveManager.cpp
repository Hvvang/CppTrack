#include "Player.h"
#include "Map.h"
#include "MoveManager.h"

MoveManager::MoveManager(std::shared_ptr<Player>& player,
                         std::shared_ptr<Map>& map) :
    m_player(player),
    m_map(map) { }

bool MoveManager::checkMove(Direction dir) const {
    size_t pos[] = {m_player->posX(), m_player->posY()};
    size_t mapSize[] = {m_map->width(), m_map->height()};
    
    if (dir == MoveManager::Direction::Up && pos[1] == 0) {
        return false;
    }
    if (dir == MoveManager::Direction::Down && pos[1] == mapSize[1] - 1 ) {
        return false;
    }
    if (dir == MoveManager::Direction::Left && pos[0] == 0) {
        return false;
    }
    if (dir == MoveManager::Direction::Right && pos[0] == mapSize[0] - 1) {
        return false;
    }
    return true;
}

void MoveManager::processInputAndMove(const std::string& inputStr) {
    if (inputStr.length() == 1) {
        Direction dir;
        switch (inputStr[0]) {
            case 'u': dir = Direction::Up;
                break;
            case 'd': dir = Direction::Down;
                break;
            case 'r': dir = Direction::Right;
                break;
            case 'l': dir = Direction::Left;
                break;
            case 'e': exit(0);
            default :
                std::cerr << "Invalid input" << '\n';
        }
        if (checkMove(dir)) {
            m_player->movePlayer(dir);
        } else {
            std::cerr << "Invalid direction" << '\n';
        }
    } else {
        std::cerr << "Invalid input" << '\n';
    }
}
