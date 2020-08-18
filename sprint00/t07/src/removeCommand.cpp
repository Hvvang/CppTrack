#include "inventory.h"

void removeCommand(std::string item, std::vector<std::string>& inventory) {
  std::string validItem[] = {"w", "f", "a", "p"};
  std::string* end = validItem + sizeof(validItem) / sizeof(validItem[0]);
  std::string* position = std::find(validItem, end, item);

  if (position != end) {
    std::vector<std::string>::iterator i =
      std::find(inventory.begin(), inventory.end(), item);

    if (i != inventory.end()) {
      inventory.erase(i);
      std::cout << item << " was removed." << std::endl;
    } else {
      std::cout << "Invalid item." << std::endl;
    }
  } else {
    std::cout << "Invalid item." << std::endl;
  }
}
