#pragma once

#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>

void uniqueWords(const std::set<std::string>& uWords,
                 const std::string& file_name);
void wordMatching(std::string& input, std::set<std::string>& uWords,
                  std::smatch& match, const std::regex& pattern);
std::string createOutputFileName(char *inFile);
