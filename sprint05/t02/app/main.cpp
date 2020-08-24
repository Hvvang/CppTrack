#include "src/Draugr.h"

void argsValidator(int argc, char **argv, std::vector<std::string>& names) {
    auto index = 0ul;
    auto value = 0ul;

    value = stoi(std::string(argv[1]), &index);
    if (argv[1][index] != '\0') {
        throw false;
    }

    std::stringstream ss((std::string(argv[2])));
    std::string tok;
    while (std::getline(ss, tok, ',')) {
        names.push_back(tok);
    }
    if (names.size() != 2) {
        throw std::invalid_argument("Invalid names");
    }
    
    value = stod(std::string(argv[3]), &index);
    if (argv[3][index] != '\0') {
        std::cerr << "/* error message */" << '\n';
        throw std::invalid_argument("Error");
    }
    if (argc == 5) {
        value = stoi(std::string(argv[4]), &index);
        if (argv[3][index] != '\0') {
            throw std::invalid_argument("Error");
        }
    }
}

int main(int argc, char** argv) {
    if (argc == 4 || argc == 5) {
        try {
            std::vector<std::string> names;
            argsValidator(argc, argv, names);
            int shoutNumber = std::stoi(std::string(argv[1]));

            if (argc == 4) {
                Draugr draugr1(std::stod(std::string(argv[3])));
                draugr1.setName(std::string(names.front()));
                draugr1.shoutPhrase(shoutNumber);
                Draugr draugr2 = draugr1;
                draugr2.setName(std::string(names.back()));
                draugr2.shoutPhrase(shoutNumber);
            } else {
                Draugr draugr1(std::stod(std::string(argv[3])), std::stoi(std::string(argv[4])));
                draugr1.setName(std::string(names.front()));
                draugr1.shoutPhrase(shoutNumber);
                Draugr draugr2 = std::move(draugr1);
                draugr2.setName(std::string(names.back()));
                draugr2.shoutPhrase(shoutNumber);
            }
        }
        catch(std::invalid_argument &e) {
            std::cerr << e.what() << '\n';
        }
    } else {
        std::cerr << "usage: ./draugr [shoutNumber] [name1,name2] [health] [frostResist]" << '\n';
    }
    return 0;
}
