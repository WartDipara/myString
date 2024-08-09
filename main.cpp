#include <iostream>
#include "my_string.h"
using std::cout;

int main()
{
    using namespace MyString;

    // Create strings
    String str1("Hello");
    String str2("World");

    // Test copy constructor
    String str3 = str1;

    // Test move constructor
    String str4 = std::move(str2);

    // Test assignment operator
    String str5("Assignment");
    str5 = str1;

    // Test move assignment operator
    String str6("Move Assignment");
    str6 = std::move(str3);

    // Test operator[]
    std::cout << "Character at index 1 in str1: " << str1[1] << std::endl;

    // Test operator==
    if (str1 == str5) {
        std::cout << "str1 and str5 are equal." << std::endl;
    } else {
        std::cout << "str1 and str5 are not equal." << std::endl;
    }

    // Test operator+
    String str7 = str1 + str5;
    std::cout << "Concatenated string: " << str7 << std::endl;


    return 0;
}