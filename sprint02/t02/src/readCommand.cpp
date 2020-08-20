#include "bookSaver.h"

void readCommand(std::map<std::string, std::vector<std::string>>& library,
                 std::string bookName) {
    std::map<std::string, std::vector<std::string>>::iterator it;

    it = library.find(bookName);
    if (it != library.end()) {
        for (const auto& content : library.find(bookName)->second) {
            std::cout << content << '\n';
        }
    } else {
        std::cerr << "invalid book" << '\n';
    }
}
