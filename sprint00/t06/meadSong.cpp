#include "meadSong.h"

void firstLine(int i, std::string* pttrn) {
  bool toggle = true;
  int it = 2;

  while (it--) {
    if (i > 0) {
      std::cout << i;
    } else {
      std::cout << pttrn[(it == 1) ? 7 : 8];
    }
    std::cout << pttrn[(i != 1) ? 1 : 0] << pttrn[2];
    if (toggle) {
      std::cout << pttrn[3] << ", ";
      toggle = false;
    } else {
      std::cout << "." << std::endl;
    }
  }
}

void secondLine(int i, std::string* pttrn) {
  if (i > 0) {
    std::cout << pttrn[(i != 1) ? 4 : 6] << pttrn[5];
  } else {
    std::cout << pttrn[9];
  }
  if (i - 1 > 0) {
    std::cout << i - 1;
  } else if (i - 1 == 0) {
    std::cout << pttrn[8];
  } else {
    std::cout << "99";
  }
  std::cout << pttrn[(i - 1 != 1) ? 1 : 0] << pttrn[2] << pttrn[3] << ".\n";
}

void showLyrics(void) {
  std::string pttrn[] = {" bottle ", " bottles ", "of mead", " on the wall",
                         "Take one ", "down and pass it around, ", "Take it ",
                         "No more", "no more",
                         "Go to the store and buy some more, "};

  for (int i = 99; i >= 0; i--) {
    firstLine(i, pttrn);
    secondLine(i, pttrn);
  }
}
