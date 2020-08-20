#include "countUniqueWords.h"

int main(int argc, char** argv) {
    if (argc == 2) {
        std::ifstream file;
        std::multiset<std::string> uWords;
        std::string line;

        file.open(argv[1]);
        if (file.is_open()) {
            std::regex pattern("[A-Za-z-\']+");
            std::smatch match;

            while (getline(file, line)) {
                wordMatching(line, uWords, match, pattern);
            }
            file.close();
            countUniqueWords(uWords, createOutputFileName(argv[1]));
        } else {
            std::cerr << "error" << "\n";
            return 1;
        }
    } else {
        std::cerr << "usage: ./countUniqueWords [file_name]" << '\n';
        return 1;
    }
    return 0;
}
