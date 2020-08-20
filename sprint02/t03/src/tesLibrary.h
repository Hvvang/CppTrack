#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>
#include <sys/stat.h>

void printContent(const std::multimap<std::string, std::string>& content);
void lineValidator(char *filePath);
void parser(std::multimap<std::string, std::string>& content,
            std::string& line);
