#include "src/Vector.h"
#include "algorithmUtils.h"
#include <string>
#include <vector>
#include <iostream>
#include <cassert>

struct Drums final {
    int badum;
    double tss;
};

bool operator==(const Drums& lhs, const Drums& rhs)
{
    return lhs.badum == rhs.badum && lhs.tss == rhs.tss;
}
int main() {
    {
        CBL::Vector<int> v{ 0, 1, 2, 3 };

        auto i = 0;
        for (auto& item : v) {
            assert(i == item);
            ++i;
        }
        assert(*v.begin() == 0);
        assert(*(v.end() - 1) == 3);
        assert(v.size() == 4);
        assert(v.capacity() >= 4);
        assert(!v.isEmpty());

        std::cout << "Simple vector OK" << std::endl;
    }

    {
        CBL::Vector<double> v;
        for (auto i = 0; i < 10; ++i) {
            v.push_back(i);
        }
        auto cpy = v;
        assert(cpy.size() == v.size());
        for (size_t i = 0; i < cpy.size(); ++i) {
            assert(cpy[i] == v[i]);
        }
        assert(v == cpy);

        cpy.push_back(3.14);

        assert(v != cpy);
        assert(v < cpy);
        assert(!(v > cpy));
        assert(v <= cpy);
        assert(!(v >= cpy));
        std::cout << "Vectors copy and comparsion OK" << std::endl;
    }
    {
        CBL::Vector<std::string> v(0);
        v.clear();
        assert(v.size() == 0);
        assert(v.isEmpty());
        std::cout << "Clear OK" << std::endl;
    }
    {
        CBL::Vector<std::string> v(10, "VAR");
        for (auto& item : v) {
            assert(item == "VAR");
        }
        v.pop_back();
        assert(v.size() == 9);
        std::cout << "Constructor and pop OK" << std::endl;
    }
    {
        CBL::Vector<float> v{ 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
        auto cpy = CBL::Vector<float>(v.begin(), v.end());
        assert(cpy == v);
        assert(cpy[2] == 3.3f);
        std::cout << "Iterator construction OK" << std::endl;
    }
    {
        CBL::Vector<char> v{ 'a', 'b', 'c', 'd', 'e' };

        auto insIt = v.insert(v.begin() + 2, 'z');
        assert(*insIt == 'z');
        insIt = v.insert(v.end(), 'k');
        assert(*insIt == 'k');
        auto ersIt = v.erase(v.begin() + 2);

        assert(ersIt);
        assert(*ersIt == 'c');
        ersIt = v.erase(v.begin(), v.end());
        assert(!ersIt);
        assert(v.size() == 0);
        assert(v.isEmpty());
        std::cout << "Iterator insertion and removal OK" << std::endl;
    }

    CBL::Vector<int> vecOfInts { 1, 2, 3, 4, 5, 5 };
    CBL::Vector<std::string> vecOfStrings { "a", "b", "c", "d", "e" };
    CBL::Vector<float> vecOfFloats { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.5f };
    CBL::Vector<Drums> vecOfMoms {
            Drums{ 10, 6.6 },
            Drums{ 100, 666.6 },
            Drums{ 100, 999.9 },
            Drums{ 9000, 2000.05 },
            Drums{ 100500, 0.3 }
    };
    // Find
    {
        auto it = Utils::Find(vecOfInts, 3);
        assert(it != vecOfInts.end() && *it == 3);
    }
    assert(Utils::Find(vecOfInts, 10) == vecOfInts.end());

    // FindIf
    {
        auto findIf = vecOfMoms;
        auto it = Utils::FindIf(vecOfMoms, [](Drums mom){
            return mom.tss == 0.3;
        });
        assert(it != vecOfMoms.end() && it->tss == 0.3);
    }
    auto findIf = vecOfMoms;
    assert(Utils::FindIf(vecOfMoms, [](Drums mom){
        return mom.tss == 3.14;
    }) == vecOfMoms.end());

    // RemoveAll
    auto remAll = vecOfInts;
    Utils::RemoveAll(remAll, 3);
    assert(Utils::Find(remAll, 3) == remAll.end());

    // RemoveAllIf
    auto remAllIf = vecOfMoms;
    Utils::RemoveAllIf(remAllIf, [](Drums mom){
        return mom.badum == 9000;
    });
    assert(Utils::FindIf(remAllIf, [](Drums mom){
        return mom.badum == 9000;
    }) == remAllIf.end());

    // Contains
    assert(Utils::Contains(vecOfStrings, "b"));
    assert(!Utils::Contains(vecOfStrings, "f"));

    // ContainsIf
    assert(Utils::ContainsIf(vecOfMoms, [](Drums mom){
        return mom.badum == 100;
    }));
    assert(!Utils::ContainsIf(vecOfMoms, [](Drums mom){
        return mom.badum == 7;
    }));

    // CountIf
    assert(Utils::CountIf(vecOfMoms, [](Drums mom){
        return mom.badum == 100;
    }) == 2);
    assert(Utils::CountIf(vecOfMoms, [](Drums mom){
        return mom.badum == 0;
    }) == 0);

    CBL::Vector<int> unsorted { 4, 7, 2, 0, -1, 60, 20, -1, 7 };

    // Sort
    {
        auto srt = unsorted;
        Utils::Sort(unsorted);
        assert(std::is_sorted(unsorted.begin(), unsorted.end()));
    }
    {
        auto srt = unsorted;
        Utils::Sort(unsorted, [](int lhs, int rhs){
            return lhs > rhs;
        });
        assert(std::is_sorted(unsorted.begin(), unsorted.end(), [](int lhs, int rhs){
            return lhs > rhs;
        }));
    }

    // Unique
    {
        auto unVec = vecOfInts;
        Utils::Unique(unVec);
        assert(unVec.size() != vecOfInts.size());
    }
    {
        auto unVec = vecOfMoms;
        Utils::Unique(unVec, [](Drums lhs, Drums rhs){
            return lhs.badum == rhs.badum;
        });
        assert(unVec.size() != vecOfMoms.size());
    }

    // ForEach
    auto lstForEach = vecOfStrings;
    Utils::ForEach(lstForEach, [](std::string& str){
        str.append("_lol");
    });
    assert(Utils::CountIf(lstForEach, [](std::string str){
        return str.find("_lol") != std::string::npos;
    }) == lstForEach.size());

    // IndexOf
    assert(Utils::IndexOf(vecOfInts, 1) == 0);
    assert(Utils::IndexOf(vecOfFloats, 0.3f) == 2);

    // IndexOfIf
    assert(Utils::IndexOfIf(vecOfMoms, [](Drums mom){
        return mom.badum == 10;
    }) == 0);
    assert(Utils::IndexOfIf(vecOfMoms, [](Drums mom){
        return mom.badum == 9000;
    }) == 3);
    return 0;
}