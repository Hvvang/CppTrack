#include "inventory.h"

void insertCommand(std::string item, std::vector<std::string>& inventory) {
  std::string validItem[] = {"w", "f", "a", "p"};
  std::string* end = validItem + sizeof(validItem) / sizeof(validItem[0]);
  std::string* position = std::find(validItem, end, item);

  if (position != end) {
    if (inventory.size() < 12) {
      inventory.push_back(item);
      std::cout << item << " was inserted." << std::endl;
    } else {
      std::cout << "Inventory is full." << std::endl;
    }
  } else {
    std::cout << "Invalid item." << std::endl;
  }
}
