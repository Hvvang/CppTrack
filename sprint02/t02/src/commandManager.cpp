#include "bookSaver.h"

std::vector<std::string> split(std::string& str) {
  std::vector<std::string> internal;
  std::istringstream iss(str);

  for(std::string s; iss >> s;)
      internal.push_back(s);
  return internal;
}

void commandManager(std::map<std::string, std::vector<std::string>>& library,
                    std::string input) {
  std::string valid[] = { "add", "delete", "read", "list", "quit" };
  std::vector<std::string> parse = split(input);
  std::string* end = valid + sizeof(valid) / sizeof(valid[0]);
  std::string* position = std::find(valid, end, parse[0]);

  if (position != end) {
    if (parse[0] == valid[0] && parse.size() == 2) {
      addCommand(library, parse[1]);
      return;
  } else if (parse[0] == valid[1] && parse.size() == 2) {
      deleteCommand(library, parse[1]);
      return;
  } else if (parse[0] == valid[2] && parse.size() == 2) {
      readCommand(library, parse[1]);
      return;
  } else if (parse[0] == valid[3] && parse.size() == 1) {
      listCommand(library);
      return;
  } else if (parse[0] == valid[4] && parse.size() == 1) {
      quitCommand();
      return;
    }
  }
  std::cout << "invalid command" << std::endl;
}
