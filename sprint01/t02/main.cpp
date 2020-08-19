#include "visitAll.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        std::deque<Info> data;
        if (!parser(data, argc, argv)) return 1;
        return bestRoute(data);
    } else {
        std::cerr << "usage: ./visitAll [[name,stamina,distance] ...]" << '\n';
        return 1;
    }
}
