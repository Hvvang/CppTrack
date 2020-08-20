#include "uniqueWords.h"

int main(int argc, char** argv) {
    if (argc == 2) {
        std::ifstream file(argv[1]);
        std::set<std::string> uWords;
        std::string line;
        struct stat s;

        if (stat(argv[1], &s) == 0 && file.is_open()) {
            if (file.is_open() && s.st_mode & S_IFREG) {
                std::regex pattern("[A-Za-z-\']+");
                std::smatch match;

                while (getline(file, line)) {
                    wordMatching(line, uWords, match, pattern);
                }
                file.close();
                uniqueWords(uWords, createOutputFileName(argv[1]));
                return 0;
            }
        }
        std::cerr << "error" << "\n";
        return 1;
    } else {
        std::cerr << "usage: ./uniqueWords [file_name]" << '\n';
        return 1;
    }
}
