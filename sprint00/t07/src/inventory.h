#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

void commandManager(std::string input, std::vector<std::string>& inventory);
void removeCommand(std::string item, std::vector<std::string>& inventory);
void insertCommand(std::string item, std::vector<std::string>& inventory);
void showCommand(const std::vector<std::string>& inventory);
void helpCommand(void);
void exitCommand(void);
