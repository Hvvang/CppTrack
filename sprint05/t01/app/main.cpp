#include "src/Draugr.h"

bool argsValidator(int argc, char **argv) {
    auto index = 0ul;
    auto value = stoi(std::string(argv[1]), &index);

    if (argv[1][index] != '\0') {
        throw false;
    }
    if (argc > 2) {
        value = stod(std::string(argv[2]), &index);
        if (argv[2][index] != '\0') {
            throw false;
        }
    }
    if (argc > 3) {
        value = stoi(std::string(argv[3]), &index);
        if (argv[3][index] != '\0') {
            throw false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc > 1 && argc < 5) {
        try {
            argsValidator(argc, argv);
            int shoutNumber = std::stoi(std::string(argv[1]));

            if (argc == 2) {
                Draugr *draugr1 = new Draugr();
                draugr1->shoutPhrase(shoutNumber);
            } else if (argc == 3) {
                Draugr draugr1(std::stod(std::string(argv[2])));
                draugr1.shoutPhrase(shoutNumber);
                // Draugr draugr2(std::stoi(std::string(argv[2])));
                // draugr2.shoutPhrase(shoutNumber);
            } else {
                Draugr draugr1(std::stod(std::string(argv[2])), std::stoi(std::string(argv[3])));
                draugr1.shoutPhrase(shoutNumber);
            }
        }
        catch(...) {
            std::cerr << "Error" << '\n';
        }
    } else {
        std::cerr << "usage: ./draugr [shoutNumber] [health] [frostResist]" << '\n';
    }
    return 0;
}
