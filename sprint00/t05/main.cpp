#include <iostream>
#include <string>

static void validator(size_t idx, char *input) {
    if (input[idx] != '\0') {
        throw false;
    }
}

int main(int argc, char **argv) {
    if (argc == 5) {
      auto index = 0ul;
      auto current = argv[2];
      try {
        auto level = stoi(std::string(argv[2]), &index);
        validator(index, argv[2]);
        current = argv[3];
        auto health = stof(std::string(argv[3]), &index);
        validator(index, argv[3]);
        current = argv[4];
        auto stamina = stod(std::string(argv[4]), &index);
        validator(index, argv[4]);
        std::cout << "Name = " << argv[1] << "\nLevel = " << level
                  << "\nHealth = " << health << "\nStamina = "
                  << stamina << std::endl;
      }
      catch (...) {
        std::cerr << "Invalid argument: " << current << std::endl;
        return 1;
      }
    } else {
      std::cerr << "usage:./automaton [name] [level] [health] [stamina]\n";
      return 1;
    }
    return 0;
}
