#include "Player.h"
#include "Map.h"
// #include "MoveManager.h"

Map::Map(size_t width, size_t height, std::shared_ptr<Player>& player) :
    m_width(width),
    m_height(height),
    m_player(player) {
    m_map = std::make_unique<char[]>(width * height);
    generateMap();
}

void Map::outputMap() const {
    int size = 0;
    int playerPos = m_player->posY() * m_width + m_player->posX();

    for (int i = 0; i < m_width * m_height; i++) {
        if (playerPos == i) {
            std::cout << m_player->getIdentifier() << " ";
        } else {
            std::cout << m_map[i] << " ";
        }
        size++;
        if (size == m_width) {
            size = 0;
            std::cout << '\n';
        }
    }
}

size_t Map::width() const {
    return m_width;
}

size_t Map::height() const {
    return m_height;
}

void Map::generateMap() {
    srand(time(NULL));
    for (int i = 0; i < m_width * m_height; i++) {
        int random = rand() % 3;
        if (random == 0) {
            m_map[i] = '.';
        } else if (random == 1) {
            m_map[i] = 'T';
        } else {
            m_map[i] = '@';
        }
    }
}
