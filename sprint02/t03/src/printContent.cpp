#include "tesLibrary.h"

void printContent(const std::multimap<std::string, std::string>& content) {
    std::string prevAuthor;
    int iter;
    
    for (const auto& [key, value] : content) {
        if (key != prevAuthor) {
            iter = 1;
            prevAuthor = key;
            std::cout << key << ":" << std::endl;
        }
        std::cout << " " << iter++ << ": " << value << '\n';
    }
}
