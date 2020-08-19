#include "stdAlgoV2.h"

static bool isNotFifteen(std::string name) {
    if (name.size() == 15) return false;
    else return true;
}

static bool filterCBL(std::string name) {
    std::transform(name.begin(), name.end(), name.begin(),
    [](unsigned char c){ return std::tolower(c); });
    if (name.find("c") != std::string::npos ||
        name.find("b") != std::string::npos ||
        name.find("l") != std::string::npos)
    return true;
    else return false;
}

static bool isLong(std::string name) {
  if (name.size() > 10) return true;
  else return false;
}

static bool isShort(std::string name) {
  if (name.size() < 4) return true;
  else return false;
}

void stdAlgoV2(std::forward_list<std::string> names, std::string file_name) {
    std::ofstream file;
    auto toRemove = std::remove_if(names.begin(), names.end(), filterCBL);
    auto prev = names.before_begin();

    for (auto it = names.begin(); it != toRemove; it++) {
        prev = it;
    }
    names.erase_after(prev, names.end());
    std::replace_if(names.begin(), names.end(), isLong, "Long one");
    std::replace_if(names.begin(), names.end(), isShort, "Short one");
    file.open(file_name);
    names.sort();
    toRemove = unique(names.begin(), names.end());
    prev = names.before_begin();
    for (auto it = names.begin(); it != toRemove; it++)
        prev = it;
    names.erase_after(prev, names.end());
    names.reverse();
    for (const auto name : names) {
        file << name << '\n';
    }
}
