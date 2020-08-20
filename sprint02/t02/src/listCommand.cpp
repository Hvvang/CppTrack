#include "bookSaver.h"

void listCommand(const std::map<std::string, std::vector<std::string>>& library) {
    for (const auto& [name, content] : library) {
        std::cout << name << '\n';
    }
}
