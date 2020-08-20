#include "bookSaver.h"

int main(int argc, char** argv) {
    if (argc == 1) {
        std::map<std::string, std::vector<std::string>> library;
        std::string input;
        while (true) {
          std::cout << "enter command:> ";
          std::getline(std::cin, input);
          commandManager(library, input);
        }
    } else {
        std::cerr << "usage: ./bookSaver" << '\n';
        return 1;
    }
    return 0;
}
