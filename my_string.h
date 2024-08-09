#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>

namespace MyString{
    class String{
    private:
        char* _buf;
        size_t _len;
        void init(const char* str);
        //support function
        bool strcmp(const char* str1,const char* str2);
        size_t strlen(const char* str);
        void strcpy(char* str1,const char* str2);
        void strcat(char* str1,const char* str2);
    public:
        String(const char* str=nullptr);
        String(const String& other);
        String(String&& other) noexcept;
        ~String();

        size_t length();
        const char* data();    

        char& operator[](size_t index);
        String& operator=(const String& other);
        String& operator=(String&& other) noexcept;
        String operator+(const String& other);
        bool operator==(const String& other);

        friend std::istream& operator>>(std::istream& is,String& str);
        friend std::ostream& operator<<(std::ostream& os,const String& str);

    };
};


#endif