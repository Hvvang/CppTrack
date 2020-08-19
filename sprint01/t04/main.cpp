#include "stdAlgoV1.h"

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
            stdAlgoV1(names);
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
