#include "inventory.h"


std::vector<std::string> split(std::string& str) {
  std::vector<std::string> internal;
  std::istringstream iss(str);

  for(std::string s; iss >> s;)
      internal.push_back(s);
  return internal;
}

void commandManager(std::string input, std::vector<std::string>& inventory) {
  std::string validCommand[] = { "remove", "insert", "show", "help", "quit" };
  std::vector<std::string> parse = split(input);
  std::string* end = validCommand + sizeof(validCommand) / sizeof(validCommand[0]);
  std::string* position = std::find(validCommand, end, parse[0]);

  if (position != end) {
    if (parse[0] == validCommand[0] && parse.size() == 2) {
      removeCommand(parse[1], inventory);
      return;
    } else if (parse[0] == validCommand[1] && parse.size() == 2) {
      insertCommand(parse[1], inventory);
      return;
    } else if (parse[0] == validCommand[2] && parse.size() == 1) {
      showCommand(inventory);
      return;
    } else if (parse[0] == validCommand[3] && parse.size() == 1) {
      helpCommand();
      return;
    } else if (parse[0] == validCommand[4] && parse.size() == 1) {
      exitCommand();
      return;
    }
  }
  std::cout << "Invalid command." << std::endl;
}
