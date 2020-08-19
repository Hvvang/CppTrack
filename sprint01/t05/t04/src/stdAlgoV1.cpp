#include "stdAlgoV1.h"

static bool isRich(std::string name) {
    std::transform(name.begin(), name.end(), name.begin(),
        [](unsigned char c){ return std::tolower(c); });
    std::size_t pos = name.find("rich");

    if (pos != std::string::npos) {
        return true;
    }
    return false;
}

static bool isVelEnd(std::string name) {
    std::transform(name.begin(), name.end(), name.begin(),
        [](unsigned char c){ return std::tolower(c); });
    std::size_t pos = name.find("vel");

    if (name.find("vel", name.size() - 3) != std::string::npos) return true;
    else return false;
}

static bool isNotFifteen(std::string name) {
    if (name.size() == 15) return false;
    else return true;
}

static bool isNotMel(std::string name) {
    std::transform(name.begin(), name.end(), name.begin(),
        [](unsigned char c){ return std::tolower(c); });
    std::size_t pos = name.find("mel");

    if (pos != std::string::npos) {
        return false;
    }
    return true;
}

void printStat(const Statistic& stat) {
    std::cout << "size: " << stat.size << '\n';
    std::cout << "contains 'rich': " << ((stat.isRich) ?
                             "true" : "false") << '\n';
    std::cout << "none of lengths is 15: " <<
                             ((stat.isNotFifteenLength) ? "true" : "false") << '\n';
    std::cout << "all end with 'vel': " <<
                             ((stat.velEnd) ? "true" : "false") << '\n';
    std::cout << "not contains 'mel': " << stat.melCount << '\n';
}

void stdAlgoV1(std::forward_list<std::string> names) {
    Statistic stat;

    stat.size = std::count_if(names.begin(), names.end(),
                              [](std::string name){return true;});
    stat.isRich = std::any_of(names.begin(), names.end(), isRich);
    stat.isNotFifteenLength = std::all_of(names.begin(),
                                          names.end(), isNotFifteen);
    stat.velEnd = std::all_of(names.begin(), names.end(), isVelEnd);
    stat.melCount = std::count_if(names.begin(), names.end(), isNotMel);
    printStat(stat);
}
