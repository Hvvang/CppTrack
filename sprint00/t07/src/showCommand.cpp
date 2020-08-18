#include "inventory.h"

void showCommand(const std::vector<std::string>& inventory) {
  int size = inventory.size();

  std::cout << "Inventory { ";
  for (const auto& item : inventory) {
    std::cout << item << " ";
  }
  while (12 - size++) {
    std::cout << "- ";
  }
  std::cout << "}" << std::endl;
}
