#pragma once

#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>
#include <sys/stat.h>

void countUniqueWords(const std::multiset<std::string>& uWords,
                      const std::string& file_name);
void wordMatching(std::string& input, std::multiset<std::string>& uWords,
                  std::smatch& match, const std::regex& pattern);
std::string createOutputFileName(char *inFile);
