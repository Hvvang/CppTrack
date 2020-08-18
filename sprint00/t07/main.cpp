#include "./src/inventory.h"

int main() {
  std::vector<std::string> inventory;

  while (true) {
    std::string input;
    std::cout << "Enter command:> ";
    std::getline(std::cin, input);

    commandManager(input, inventory);
  }
  return 0;
}
