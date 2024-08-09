#include <iostream>
#include "my_string.h"
using std::cout;

int main()
{
    using namespace MyString;

    String str1("Hello");
    cout << str1.data() << '\n';
    cout << str1.length() << '\n';
    cout << "----------\n";
    String str2 = "Word";
    cout << str2 << '\n';
    cout << "----------\n";
    String str3 = str1 + str2;
    cout << str3.data() << '\n';
    cout << str3.length() << '\n';
    return 0;
}