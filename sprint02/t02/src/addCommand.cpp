#include "bookSaver.h"

void addCommand(std::map<std::string, std::vector<std::string>>& library,
                std::string bookName) {
    const std::string libraryPath("./library/");
    struct stat s;
    std::string bookPath = libraryPath + bookName;

    if (stat(bookPath.c_str(), &s) == 0) {
        std::ifstream file(bookPath);

        if (file.is_open() && s.st_mode & S_IFREG) {
            std::string line;

            if (library.find(bookName) != library.end()) {
                library.erase(library.find(bookName));
            }
            while (getline(file, line)) {
                library[bookName].push_back(line);
            }
            file.close();
            std::cout << bookName << " added" << '\n';
            return;
        }
    }
    std::cerr << "invalid book" << "\n";
}
