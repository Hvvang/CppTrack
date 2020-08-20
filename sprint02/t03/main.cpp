#include "tesLibrary.h"

int main(int argc, char** argv) {
    if (argc == 2) {
        struct stat s;

        if (stat(argv[1], &s) == 0 && s.st_mode & S_IFREG) {
            lineValidator(argv[1]);
        } else {
            std::cerr << "error" << "\n";
            return 1;
        }
    } else {
        std::cerr << "usage: ./tesLibrary [file_name]" << '\n';
        return 1;
    }
    return 0;
}
