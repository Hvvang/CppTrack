#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include "../utils/algorithmUtils.h"

#include <sstream>
#include <stdexcept>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream &operator<<(ostream &os, const vector<T> &s)
{
    os << "{";
    bool first = true;
    for (const auto &x : s)
    {
        if (!first)
        {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream &operator<<(ostream &os, const list<T> &s)
{
    os << "{";
    bool first = true;
    for (const auto &x : s)
    {
        if (!first)
        {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream &operator<<(ostream &os, const forward_list<T> &s)
{
    os << "{";
    bool first = true;
    for (const auto &x : s)
    {
        if (!first)
        {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream &operator<<(ostream &os, const set<T> &s)
{
    os << "{";
    bool first = true;
    for (const auto &x : s)
    {
        if (!first)
        {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream &operator<<(ostream &os, const map<K, V> &m)
{
    os << "{";
    bool first = true;
    for (const auto &kv : m)
    {
        if (!first)
        {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template <class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint = {})
{
    if (!(static_cast<int>(t) == static_cast<int>(u)))
    {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty())
        {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

inline void Assert(bool b, const string &hint)
{
    AssertEqual(b, true, hint);
}

class TestRunner
{
 public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string &test_name)
    {
        try
        {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception &e)
        {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...)
        {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner()
    {
        if (fail_count > 0)
        {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

 private:
    int fail_count = 0;
};

#define ASSERT_EQUAL(x, y)                                   \
    {                                                        \
        ostringstream test_assert_equal_os;                  \
        test_assert_equal_os << #x << " != " << #y << ", "   \
                             << __FILE__ << ":" << __LINE__; \
        AssertEqual(x, y, test_assert_equal_os.str());       \
    }

#define ASSERT(x)                                      \
    {                                                  \
        ostringstream test_assert_os;                  \
        test_assert_os << #x << " is false, "          \
                       << __FILE__ << ":" << __LINE__; \
        Assert(x, test_assert_os.str());               \
    }

#define RUN_TEST(tr, func) \
    tr.RunTest(func, #func)
/*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*/

void TestIsInRange()
{
    ASSERT_EQUAL(IsInRange(2, 5, 10), false);
    ASSERT_EQUAL(IsInRange(-12345678, INT_MIN, INT_MAX), true);
    ASSERT_EQUAL(IsInRange(-12345678, 0, 1000), false);
    ASSERT_EQUAL(IsInRange(2, -5, 10), true);
    ASSERT_EQUAL(IsInRange(-2, -123846, 109876521), true);
    ASSERT_EQUAL(IsInRange(-5, -5, 10), true);
    ASSERT_EQUAL(IsInRange(109876521, -123846, 109876521), true);
}

void TestIsInRangePair()
{
    ASSERT_EQUAL(IsInRange(2, {5, 10}), false);
    ASSERT_EQUAL(IsInRange(-12345678, {INT_MIN, INT_MAX}), true);
    ASSERT_EQUAL(IsInRange(-12345678, {0, 1000}), false);
    ASSERT_EQUAL(IsInRange(2, {-5, 10}), true);
    ASSERT_EQUAL(IsInRange(-2, {-123846, 109876521}), true);
    ASSERT_EQUAL(IsInRange(-5, {-5, 10}), true);
    ASSERT_EQUAL(IsInRange(109876521, {-123846, 109876521}), true);
}

void TestIsInRangeInside()
{
    ASSERT_EQUAL(IsInsideRange(2, 5, 10), false);
    ASSERT_EQUAL(IsInsideRange(-12345678, INT_MIN, INT_MAX), true);
    ASSERT_EQUAL(IsInsideRange(-12345678, 0, 1000), false);
    ASSERT_EQUAL(IsInsideRange(2, -5, 10), true);
    ASSERT_EQUAL(IsInsideRange(-2, -123846, 109876521), true);
    ASSERT_EQUAL(IsInsideRange(-5, -5, 10), false);
    ASSERT_EQUAL(IsInsideRange(109876521, -123846, 109876521), false);
}

void TestIsInRangePairInside()
{
    ASSERT_EQUAL(IsInsideRange(2, {5, 10}), false);
    ASSERT_EQUAL(IsInsideRange(-12345678, {INT_MIN, INT_MAX}), true);
    ASSERT_EQUAL(IsInsideRange(-12345678, {0, 1000}), false);
    ASSERT_EQUAL(IsInsideRange(2, {-5, 10}), true);
    ASSERT_EQUAL(IsInsideRange(-2, {-123846, 109876521}), true);
    ASSERT_EQUAL(IsInsideRange(-5, {-5, 10}), false);
    ASSERT_EQUAL(IsInsideRange(109876521, {-123846, 109876521}), false);
}

void TestModify()
{
    {
        int a = 5;
        int b = -4;
        ASSERT_EQUAL(Modify(a, move(b)), true);
        ASSERT_EQUAL(a, -4);
    }
    {
        int a = 5;
        int b = 5;
        ASSERT_EQUAL(Modify(a, move(b)), false);
        ASSERT_EQUAL(a, 5);
    }
}

void TestRemove()
{
    vector<int> v{1, 2, 3, 4, 3, 3, 5};
    list<int> l{1, 2, 3, 4, 5};
    forward_list<int> fl{1, 2, 3, 4, 5};

    vector<int> vr{1, 2, 4, 5};
    list<int> lr{1, 2, 4, 5};
    forward_list<int> flr{1, 2, 4, 5};

    RemoveAll(v, 3);
    RemoveAll(l, 3);
    RemoveAll(fl, 3);

    ASSERT(equal(v.begin(), v.end(), vr.begin()));
    ASSERT(equal(l.begin(), l.end(), lr.begin()));
    ASSERT(equal(fl.begin(), fl.end(), flr.begin()));
}

void TestRemoveIf()
{
    vector<int> v{1, 2, 3, 4, 3, 3, 5};
    list<int> l{1, 2, 3, 4, 5};
    forward_list<int> fl{1, 2, 3, 4, 5};

    RemoveAllIf(v, [](const auto &a) { return a == 3; });
    RemoveAllIf(l, [](const auto &a) { return a == 3; });
    RemoveAllIf(fl, [](const auto &a) { return a == 3; });

    vector<int> vr{1, 2, 4, 5};
    list<int> lr{1, 2, 4, 5};
    forward_list<int> flr{1, 2, 4, 5};

    ASSERT(equal(v.begin(), v.end(), vr.begin()));
    ASSERT(equal(l.begin(), l.end(), lr.begin()));
    ASSERT(equal(fl.begin(), fl.end(), flr.begin()));
}

void TestFind()
{
    vector<int> v{1, 2, 3, 4, 3, 3, 5};
    list<int> l{1, 2, 3, 4, 5};
    forward_list<int> fl{1, 2, 3, 4, 5};

    ASSERT_EQUAL(*Find(v, 3), *(v.begin() + 2));
    ASSERT_EQUAL(*Find(l, 3), *next(next(l.begin())));
    ASSERT_EQUAL(*Find(fl, 3), *next(next(fl.begin())));
}

void TestFindIf()
{
    vector<int> v{1, 2, 3, 4, 3, 3, 5};
    list<int> l{1, 2, 3, 4, 5};
    forward_list<int> fl{1, 2, 3, 4, 5};

    ASSERT_EQUAL(*FindIf(v, [](const auto &a) { return a == 3; }), *(v.begin() + 2));
    ASSERT_EQUAL(*FindIf(l, [](const auto &a) { return a == 3; }), *next(next(l.begin())));
    ASSERT_EQUAL(*FindIf(fl, [](const auto &a) { return a == 3; }), *next(next(fl.begin())));
}
//
void TestContains()
{
    vector<int> v{1, 2, 3, 4, 3, 3, 5};
    list<int> l{1, 2, 3, 4, 5};
    forward_list<int> fl{1, 2, 3, 4, 5};

    ASSERT_EQUAL(Contains(v, 3), true);
    ASSERT_EQUAL(Contains(l, 3), true);
    ASSERT_EQUAL(Contains(fl, 3), true);

    ASSERT_EQUAL(Contains(v, 100), false);
    ASSERT_EQUAL(Contains(l, 100), false);
    ASSERT_EQUAL(Contains(fl, 100), false);
}

void TestContainsIf()
{
    vector<int> v{1, 2, 3, 4, 3, 3, 5};
    list<int> l{1, 2, 3, 4, 5};
    forward_list<int> fl{1, 2, 3, 4, 5};

    ASSERT_EQUAL(ContainsIf(v, [](const auto &a) { return a == 3; }), true);
    ASSERT_EQUAL(ContainsIf(l, [](const auto &a) { return a == 3; }), true);
    ASSERT_EQUAL(ContainsIf(fl, [](const auto &a) { return a == 3; }), true);

    ASSERT_EQUAL(ContainsIf(v, [](const auto &a) { return a == 10; }), false);
    ASSERT_EQUAL(ContainsIf(l, [](const auto &a) { return a == 10; }), false);
    ASSERT_EQUAL(ContainsIf(fl, [](const auto &a) { return a == 10; }), false);
}

void TestCountIf()
{
    vector<int> v{1, -2, 3, 4, -3, 3, 5};
    list<int> l{-1, 2, 3, -4, 5};
    forward_list<int> fl{1, 2, 3, -4, -5};

    ASSERT_EQUAL(CountIf(v, [](const auto &a) { return a < 0; }), 2);
    ASSERT_EQUAL(CountIf(l, [](const auto &a) { return a < 0; }), 2);
    ASSERT_EQUAL(CountIf(fl, [](const auto &a) { return a < 0; }), 2);

    ASSERT_EQUAL(CountIf(v, [](const auto &a) { return a > 10; }), 0);
    ASSERT_EQUAL(CountIf(l, [](const auto &a) { return a > 10; }), 0);
    ASSERT_EQUAL(CountIf(fl, [](const auto &a) { return a > 10; }), 0);
}

void TestMin()
{
    ASSERT_EQUAL(Min(4, 2, 6, 1, 8, 345, 234, 4, -2), -2);
}

void TestMax()
{
    ASSERT_EQUAL(Max(4, 2, 6, 1, 8, 345, 234, 4, -2), 345);
}

void TestMaxElement()
{
    vector<int> v{1, -2, 3, 4, -3, 3, 5, -6};
    list<int> l{-1, 2, 3, -4, 5, -8};
    forward_list<int> fl{1, 2, 3, -4, -5};

    ASSERT_EQUAL(MaxElement(v), 5);
    ASSERT_EQUAL(MaxElement(l), 5);
    ASSERT_EQUAL(MaxElement(fl), 3);
}

void TestMinElement()
{
    vector<int> v{1, -2, 3, 4, -3, 3, 5, -6};
    list<int> l{-1, 2, 3, -4, 5, -8};
    forward_list<int> fl{1, 2, 3, -4, -5};

    ASSERT_EQUAL(MinElement(v), -6);
    ASSERT_EQUAL(MinElement(l), -8);
    ASSERT_EQUAL(MinElement(fl), -5);
}

void TestMaxElementComp()
{
    vector<int> v{3, 1, -14, 1, 5, 9};
    list<int> l{3, 1, -14, 1, 5, 9};
    forward_list<int> fl{3, 1, -14, 1, 5, 9};

    ASSERT_EQUAL(MaxElement(v, [](int a, int b) { return (std::abs(a) < std::abs(b)); }), -14);
    ASSERT_EQUAL(MaxElement(l, [](int a, int b) { return (std::abs(a) < std::abs(b)); }), -14);
    ASSERT_EQUAL(MaxElement(fl, [](int a, int b) { return (std::abs(a) < std::abs(b)); }), -14);
}

void TestMinElementComp()
{
    vector<int> v{-3, 1, -14, -2, -5, -9};
    list<int> l{-3, 1, -14, -2, -5, -9};
    forward_list<int> fl{-3, 1, -14, -2, -5, -9};

    ASSERT_EQUAL(MinElement(v, [](int a, int b) { return (std::abs(a) < std::abs(b)); }), 1);
    ASSERT_EQUAL(MinElement(l, [](int a, int b) { return (std::abs(a) < std::abs(b)); }), 1);
    ASSERT_EQUAL(MinElement(fl, [](int a, int b) { return (std::abs(a) < std::abs(b)); }), 1);
}

void TestUnique()
{
    vector<int> v{1, 2, 2, 3, 4, 4, 4, 5, 5};
    list<int> l{1, 2, 2, 3, 4, 4, 4, 5, 5};
    forward_list<int> fl{1, 2, 2, 3, 4, 4, 4, 5, 5};

    vector<int> vr{1, 2, 3, 4, 5};
    list<int> lr{1, 2, 3, 4, 5};
    forward_list<int> flr{1, 2, 3, 4, 5};

    Unique(v);
    Unique(l);
    Unique(fl);

    ASSERT(equal(v.begin(), v.end(), vr.begin()));
    ASSERT(equal(l.begin(), l.end(), lr.begin()));
    ASSERT(equal(fl.begin(), fl.end(), flr.begin()));
}

void TestUniqueIf()
{
    vector<int> v{1, 2, 2, 3, 4, 4, 4, 5, 5};
    list<int> l{1, 2, 2, 3, 4, 4, 4, 5, 5};
    forward_list<int> fl{1, 2, 2, 3, 4, 4, 4, 5, 5};

    vector<int> vr{1, 2, 2, 3, 4, 5, 5};
    list<int> lr{1, 2, 2, 3, 4, 5, 5};
    forward_list<int> flr{1, 2, 2, 3, 4, 5, 5};

    Unique(v, [](const auto &a, const auto &b) { return a == 4; });
    Unique(l, [](const auto &a, const auto &b) { return a == 4; });
    Unique(fl, [](const auto &a, const auto &b) { return a == 4; });

    ASSERT(equal(v.begin(), v.end(), vr.begin()));
    ASSERT(equal(l.begin(), l.end(), lr.begin()));
    ASSERT(equal(fl.begin(), fl.end(), flr.begin()));
}

void TestIntexOf()
{
    vector<int> v{1, 2, 2, 3, 4, 3, 3, 5, 5};
    list<int> l{1, 2, 2, 3, 4, 3, 3, 5, 5};
    forward_list<int> fl{1, 2, 2, 3, 4, 3, 3, 5, 5};

    ASSERT_EQUAL(IndexOf(v, 3), 3);
    ASSERT_EQUAL(IndexOf(l, 3), 3);
    ASSERT_EQUAL(IndexOf(fl, 3), 3);

    ASSERT_EQUAL(IndexOf(v, 10), v.size());
    ASSERT_EQUAL(IndexOf(l, 10), l.size());
    ASSERT_EQUAL(IndexOf(fl, 10), std::distance(fl.begin(), fl.end()));
}

void TestIntexOfPred()
{
    vector<int> v{1, 2, 2, 3, 4, 3, 3, 5, 5};
    list<int> l{1, 2, 2, 3, 4, 3, 3, 5, 5};
    forward_list<int> fl{1, 2, 2, 3, 4, 3, 3, 5, 5};

    ASSERT_EQUAL(IndexOfIf(v, [](const auto &a) { return a == 3; }), 3);
    ASSERT_EQUAL(IndexOfIf(l, [](const auto &a) { return a == 3; }), 3);
    ASSERT_EQUAL(IndexOfIf(fl, [](const auto &a) { return a == 3; }), 3);

    ASSERT_EQUAL(IndexOfIf(v, [](const auto &a) { return a == 10; }), v.size());
    ASSERT_EQUAL(IndexOfIf(l, [](const auto &a) { return a == 10; }), l.size());
    ASSERT_EQUAL(IndexOfIf(fl, [](const auto &a) { return a == 10; }), std::distance(fl.begin(), fl.end()));
}

int main()
{
    TestRunner tr;

    RUN_TEST(tr, TestIsInRange);
    RUN_TEST(tr, TestIsInRangePair);
    RUN_TEST(tr, TestIsInRangeInside);
    RUN_TEST(tr, TestIsInRangePairInside);
    RUN_TEST(tr, TestModify);
    RUN_TEST(tr, TestRemove);
    RUN_TEST(tr, TestRemoveIf);
    RUN_TEST(tr, TestFind);
    RUN_TEST(tr, TestFindIf);
    RUN_TEST(tr, TestContains);
    RUN_TEST(tr, TestContainsIf);
    RUN_TEST(tr, TestCountIf);
    RUN_TEST(tr, TestMin);
    RUN_TEST(tr, TestMax);
    RUN_TEST(tr, TestMaxElement);
    RUN_TEST(tr, TestMinElement);
    RUN_TEST(tr, TestMaxElementComp);
    RUN_TEST(tr, TestMinElementComp);
    RUN_TEST(tr, TestUnique);
    RUN_TEST(tr, TestUniqueIf);
    RUN_TEST(tr, TestIntexOf);
    RUN_TEST(tr, TestIntexOfPred);
}
