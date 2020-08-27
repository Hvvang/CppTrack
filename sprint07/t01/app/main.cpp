#include "src/String.h"
#include "src/WString.h"
#include "algorithmUtils.h"
#include <string>
#include <vector>
#include <iostream>
#include <cassert>

int main() {
    {
        CBL::String str;
		assert(str.length() == 0);
        str = "OH MY";
		assert(str == "OH MY");
		std::cout << "Simple string OK" << std::endl;
    }
   {
       CBL::String str = "Hello Tamriel";
       auto strCpy = str;
		assert(str == strCpy);
       str = CBL::String(str, 2);
		assert(str == "llo Tamriel");
       str = CBL::String(strCpy, 2, 3);
		assert(str == "llo");
       CBL::String itStr(strCpy.begin() + 6, strCpy.end());
		assert(itStr == "Tamriel");
		assert(itStr.front() == 'T');
		assert(itStr.back() == 'l');
		str = CBL::String(10, 'k');
		assert(str == "kkkkkkkkkk");
		str = '!';
		assert(str == "!");
		std::cout << "Constructors OK" << std::endl;
	}
   {
       CBL::String str1 = "Hello";
       CBL::String str2 = " Tamriel";
       str1 += str2;
		assert(str1 == "Hello Tamriel");
       str1 += " lol";
		assert(str1 == "Hello Tamriel lol");
       str1 += '!';
		assert(str1 == "Hello Tamriel lol!");
		std::cout << "String concat OK" << std::endl;
	}
   {
       CBL::WString st = L"class";
       CBL::WString str = L"The standard string class provides support for such objects with"
                         "an interface similar to that of a standard container of bytes, but"
                         "adding features specifically designed to operate with strings of"
                         "single-byte characters.";
        assert(str.find('p') == 26);
        assert(str.find('p', 30) == 37);
        assert(str.find('p', 210) == CBL::String::npos);

        assert(str.rfind('p') == 26);
        assert(str.rfind('p', 173) == CBL::WString::npos);
        assert(str.rfind('p', 210) == CBL::WString::npos);

        assert(str.find(L"class") == 20);
        assert(str.find(CBL::WString(L"class"), 20) == 20);
        assert(str.find(L"of") == 93);
        assert(str.find(L"of", 170) == 192);

        assert(str.rfind(L"class", 50) == CBL::WString::npos);
        assert(str.rfind(CBL::WString(L"class"), 20) == 20);
        assert(str.rfind(L"of") == 192);
        assert(str.rfind(L"of", 170) == 117);

        std::cout << "Find OK" << std::endl;
   }
   {
       CBL::String st = "class";
       CBL::String str = "The standard string class provides support for such objects with"
                         "an interface similar to that of a standard container of bytes, but"
                         "adding features specifically designed to operate with strings of"
                         "single-byte characters.";

     std::string st1 = "class";
     std::string str1 = "The standard string class provides support for such objects with"
                       "an interface similar to that of a standard container of bytes, but"
                       "adding features specifically designed to operate with strings of"
                       "single-byte characters.";

        assert(str.find('p') == str1.find('p'));
        assert(str.find('p', 30) == str1.find('p', 30));
        assert(str.find('p', 210) == str1.find('p', 210));

        assert(str.rfind('p') == str1.rfind('p'));
        assert(str.rfind('p', 173) == str1.rfind('p', 173));
        assert(str.rfind('p', 210) == str1.rfind('p', 210));

        assert(str.find("class") == str1.find("class"));
        assert(str.find(CBL::String("class"), 20) == str1.find(std::string("class"), 20));
        assert(str.find("of") == str1.find("of"));
        assert(str.find("of", 170) == str1.find("of", 170));

        assert(str.rfind("class", 50) == str1.rfind("class", 50));
        assert(str.rfind(CBL::String("class"), 20) == str1.rfind(std::string("class"), 20));
        assert(str.rfind("of") == str1.rfind("of"));
        assert(str.rfind("of", 170) == str1.rfind("of", 170));

        std::cout << "Find OK" << std::endl;
   }

   {
       CBL::WString st = L"class";
       CBL::WString str = L"The standard string class provides support for such objects with"
                         "an interface similar to that of a standard container of bytes, but"
                         "adding features specifically designed to operate with strings of"
                         "single-byte characters.";

       std::wstring st1 = L"class";
       std::wstring str1 = L"The standard string class provides support for such objects with"
                         "an interface similar to that of a standard container of bytes, but"
                         "adding features specifically designed to operate with strings of"
                         "single-byte characters.";

        assert(str.find('p') == str1.find('p'));
        assert(str.find('p', 30) == str1.find('p', 30));
        assert(str.find('p', 210) == str1.find('p', 210));

        assert(str.rfind('p') == str1.rfind('p'));
        assert(str.rfind('p', 173) == str1.rfind('p', 173));
        assert(str.rfind('p', 210) == str1.rfind('p', 210));

        assert(str.find(L"class") == str1.find(L"class"));
        assert(str.find(CBL::WString(L"class"), 20) == str1.find(std::wstring(L"class"), 20));
        assert(str.find(L"of") == str1.find(L"of"));
        assert(str.find(L"of", 170) == str1.find(L"of", 170));

        assert(str.rfind(L"class", 50) == str1.rfind(L"class", 50));
        assert(str.rfind(CBL::WString(L"class"), 20) == str1.rfind(std::wstring(L"class"), 20));
        assert(str.rfind(L"of") == str1.rfind(L"of"));
        assert(str.rfind(L"of", 170) == str1.rfind(L"of", 170));

        std::cout << "Find OK" << std::endl;
   }
   {
       CBL::String str = "some string";
		assert(str.compare("some string") == 0);
		assert(str.compare(str) == 0);
		assert(str.compare("some stri") > 0);
		assert(str.compare("DINGLE BOB") > 0);
		assert(str.compare("z") < 0);
		std::cout << "Comparsion OK" << std::endl;
   }
   {
       CBL::String str;
       str += CBL::String("1") + "2";
       str += "3" + CBL::String("4");
       str += CBL::String("5") + CBL::String("6");
       str += CBL::String("7") + '8';
       str += '9' + CBL::String("0");
		assert(str == "1234567890");
		std::cout << "Concat operators OK" << std::endl;
   }
   {
       CBL::String str1 = "lol";
       CBL::String str2 = "kek";
		assert(!(str1 == str2));
		assert(str1 != str2);
		assert(!(str1 <= str2));
		assert(!(str1 < str2));
		assert(str1 >= str2);
		assert(str1 > str2);
		std::cout << "Comparsion operators OK" << std::endl;
   }
	return 0;
}
