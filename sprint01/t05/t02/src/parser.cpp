#include "visitAll.h"

static std::vector<std::string> split(std::string str, char delimiter) {
    std::vector<std::string> internal;
    std::stringstream ss(str);
    std::string tok;

    while(std::getline(ss, tok, delimiter))
        internal.push_back(tok);
    return internal;
}

static bool checker(std::vector<std::string> data, Info& info) {
    if (data.size() == 3) {
        size_t index;

        info.name = data[0];
        info.stamina = stoi(data[1], &index);
        if (data[1][index] != '\0') return false;
        info.distance = stoi(data[2], &index);
        if (data[2][index] != '\0') return false;
    } else {
        std::cerr << "Invalid town data" << '\n';
        return false;
    }
    return true;
}

bool parser(std::deque<Info>& data, int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        Info info;
        std::vector<std::string> elements = split(std::string(argv[i]), ',');

        if (!checker(elements, info)) {
            std::cerr << "Argument " << argv[i] << " is not valid" << std::endl;
            return false;
        }
        else {
            data.push_back(info);
        }
    }
    return true;
}
