#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <sys/stat.h>

void commandManager(std::map<std::string, std::vector<std::string>>& library,
                    std::string input);
void deleteCommand(std::map<std::string, std::vector<std::string>>& library,
                   std::string bookName);
void addCommand(std::map<std::string, std::vector<std::string>>& library,
                std::string bookName);
void readCommand(std::map<std::string, std::vector<std::string>>& library,
                 std::string bookName);
void listCommand(const std::map<std::string, std::vector<std::string>>& library);
void quitCommand(void);
