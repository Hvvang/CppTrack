#include "stdAlgoV2.h"

std::string createOutputFileName(char *inFile) {
    std::string input(inFile);
    std::stringstream ss(input);
    std::string tok;
    size_t index;

    while(std::getline(ss, tok, '/'));
    if ((index = tok.rfind(".")) != std::string::npos) {
            tok.insert(index, "_mod");
            return tok;
    } else return tok + "_mod";
}

int main(int argc, char** argv) {
    if (argc == 2) {
        std::ifstream file;
        std::forward_list<std::string> names;
        std::string line;

        file.open(argv[1]);
        if (file.is_open()) {
            while (getline(file, line)) {
                names.push_front(line);
            }
            file.close();
            stdAlgoV2(names, createOutputFileName(argv[1]));
        } else {
            std::cerr << "error" << "\n";
            return 1;
        }
    } else {
        std::cerr << "usage: ./stdAlgoV1 [file_name]" << '\n';
        return 1;
    }
    return 0;
}
