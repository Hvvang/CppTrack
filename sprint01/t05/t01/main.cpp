#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

bool checker(std::string name) {
    std::string valid[] = { "mercer", "emer", "jim" };

    std::transform(name.begin(), name.end(), name.begin(),
        [](unsigned char c){ return std::tolower(c); });
    for (const auto& it : valid) {
        if (name.find(it) != std::string::npos) {
            return true;
        }
    }
    return false;
}

int main(int argc, char** argv) {
    if (argc > 1) {
        std::vector<std::string> data;

        for (int i = 1; i < argc; i++) {
            data.push_back(std::string(argv[i]));
        }
        for (const auto& it : data) {
            if (checker(it)) {
                std::cout << it << ", move along!\n";
            }
        }
    } else {
        std::cerr << "usage: ./moveAlong [args]" << '\n';
    }
}
