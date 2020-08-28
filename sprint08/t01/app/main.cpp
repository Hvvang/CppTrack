#include "ClassWithInitializerList.h"

int main() {
    ClassWithInitializerList<int> c1{1, 2, 3, 4, 5};
    ClassWithInitializerList<char> c2('a', 'b', 'c', 'd', 'e');
    std::vector<std::string> vec{"one", "two", "three"};
    ClassWithInitializerList<std::string> c3(vec);
    c1.outputVector();
    std::cout << std::endl;
    c2.outputVector();
    std::cout << std::endl;
    c3.outputVector();
    return 0;
}
