#include "src/Draugr.h"

bool argsValidator(char **argv, int& shoutNumber) {
    auto index = 0ul;

    shoutNumber = stoi(std::string(argv[1]), &index);
    if (argv[1][index] != '\0') {
        throw false;
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc == 2) {
        try {
            int shoutNumber = -1;
            argsValidator(argv, shoutNumber);

            Draugr draugr;
            draugr.shoutPhrase(shoutNumber);
        }
        catch(...) {
            std::cerr << "Invalid argument" << '\n';
        }
    } else {
        std::cerr << "usage: ./draugr [shoutNumber]" << '\n';
    }
    return 0;
}
