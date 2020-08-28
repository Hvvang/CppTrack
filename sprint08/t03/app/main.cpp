#include "Bind.h"

int main() {
    std::cout << "===========" << std::endl;
    std::cout << SpecializedFunctions::Math::pow2<int>(10) << std::endl;
    std::cout << SpecializedFunctions::Math::pow2<double>(10.01) << std::endl;
    std::cout << "===========" << std::endl;
    std::cout << SpecializedFunctions::Math::iDontWontToCalculate() << std::endl;
    std::cout << "===========" << std::endl;
    SpecializedFunctions::Output::outputWeird3Arguments<std::string>("Hey", "it's not", "right");
    SpecializedFunctions::Output::outputWeird3Arguments<std::string>("right", "This", "is");
    SpecializedFunctions::Output::outputFusRoDah();
    SpecializedFunctions::Output::outputLovelyWords("Are", "you", "kidding", "?");
    std::cout << "===========" << std::endl;
    return 0;
}
