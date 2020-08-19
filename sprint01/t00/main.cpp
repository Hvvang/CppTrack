#include <array>
#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, char** argv) {
    if (argc == 6) {
        std::array<std::string, 5> data;

        for (int i = 1; i < argc; i++) {
            data[i - 1] = std::string(argv[i]);
        }
        std::sort(data.begin(), data.end());
        for (const auto& it : data) {
            std::cout << it << " ";
        }
        std::cout << std::endl;
        return 0;
    } else {
        std::cerr << "usage: ./simpleSort arg1 arg2 arg3 arg4 arg5" << '\n';
        return 1;
    }
}
