#include "inventory.h"

void helpCommand(void) {
  std::cout << "1. insert <itemType>" << std::endl;
  std::cout << "2. remove <itemType>" << std::endl;
  std::cout << "3. show inventory" << std::endl;
  std::cout << "4. help" << std::endl;
  std::cout << "5. exit" << std::endl;
}
