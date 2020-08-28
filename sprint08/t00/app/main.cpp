#include "src/Player.h"
#include "src/Map.h"
#include "src/MoveManager.h"

void argsValidator(char **argv, int& width, int& height) {
    auto index = 0ul;

    width = stoi(std::string(argv[1]), &index);
    if (argv[1][index] != '\0') {
        throw std::invalid_argument("Invalid argument");
    }
    height = stoi(std::string(argv[2]), &index);
    if (argv[2][index] != '\0') {
        throw std::invalid_argument("Invalid argument");
    }
}

int main(int argc, char **argv) {
    if (argc == 3) {
        int width = 0;
        int height = 0;
        argsValidator(argv, width, height);
        if (width > 4 && width < 21 && height > 4 && height < 21) {
            auto p = std::make_shared<Player>();
            auto m = std::make_shared<Map>(width, height, p);
            auto mm = std::make_shared<MoveManager>(p, m);

            std::string input;
            m->outputMap();
            while (true) {
                std::cout << ":> ";
                std::getline(std::cin, input);
                mm->processInputAndMove(input);
                m->outputMap();
            }
        } else {
            throw std::invalid_argument("Invalid map size");
        }
    } else {
        std::cerr << "usage: ./smartPointers [width] [height]" << '\n';
    }
    return 0;
}
