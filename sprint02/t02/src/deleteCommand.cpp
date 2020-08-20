#include "bookSaver.h"

void deleteCommand(std::map<std::string, std::vector<std::string>>& library,
                   std::string bookName) {
    std::map<std::string, std::vector<std::string>>::iterator it;

    if ((it = library.find(bookName)) != library.end()) {
        library.erase(it);
        std::cout << bookName << " deleted" << '\n';
    } else {
        std::cerr << "invalid book" << '\n';
    }
}
