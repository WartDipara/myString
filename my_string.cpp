#include "my_string.h"
#include <iostream>
using std::cout;

namespace MyString
{
    // support function
    size_t String::strlen(const char *str)
    {
        size_t i = 0;
        while (str[i] != '\0')
            i++;
        return i;
    }
    void String::strcpy(char *str1, const char *str2)
    {
        size_t len_str1 = strlen(str1);
        size_t len_str2 = strlen(str2);
        if (len_str1 < len_str2)
        {
            delete[] str1;
            str1 = new char[len_str2 + 1];
        }
        for (size_t i = 0; i < len_str2; i++)
        {
            str1[i] = str2[i];
        }
        str1[len_str2] = '\0';
    }
    void String::init(const char *str)
    {
        if (str == nullptr)
        {
            _buf = nullptr;
            _len = 0;
        }
        else
        {
            _len = strlen(str);
            _buf = new char[_len + 1];
            strcpy(_buf, str);
        }
    }
    bool String::strcmp(const char *str1, const char *str2)
    {
        size_t len_str1 = strlen(str1);
        size_t len_str2 = strlen(str2);
        if (len_str1 != len_str2)
            return false;
        for (size_t i = 0; i < len_str1; i++)
        {
            if (str1[i] != str2[i])
                return false;
        }
        return true;
    }
    void String::strcat(char *str1, const char *str2)
    {
        size_t len_str1 = strlen(str1);
        size_t len_str2 = strlen(str2);
        char *p = str1 + len_str1;
        while (*str2 != '\0')
        {
            *p++ = *str2++;
        }
        *p = '\0';
    }
    // main function
    size_t String::length()
    {
        if (0 == _len)
            _len = strlen(_buf);
        return _len;
    }
    const char *String::data()
    {
        return _buf;
    }

    String::String(const char *str)
    {
        init(str);
        cout << " default constructor (" << *this << ") \n";
    }
    String::String(const String &other)
    {
        init(other._buf);
        cout << " copy constructor (" << *this << ") \n";
    }
    String::String(String &&other) noexcept : _buf(nullptr), _len(0)
    {
        _buf = other._buf;
        _len = other._len;
        other._buf = nullptr;
        other._len = 0;
        cout << "move construction (" << *this << ") \n";
    }
    String::~String()
    {
        cout << "destructor (" << *this << ")\n";
        delete[] _buf;
    }
    /*  diff
        copy constructor creates a new instance of an obj using the val of the incoming obj
        assignment operator copy val of an obj to an exist instance
    */
    String &String::operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] _buf;
            init(other._buf);
        }
        cout << " copy assign opr (" << *this << ") \n";
        return *this;
    }
    String &String::operator=(String &&other) noexcept
    {
        if (this != &other)
        {
            _buf = nullptr;
            _buf = other._buf;
            _len = other._len;
            other._buf = nullptr;
            other._len = 0;
        }
        cout << " mov assign opr (" << *this << ") \n";
        return *this;
    }
    char &String::operator[](size_t index)
    {
        if (index >= _len)
        {
            throw std::out_of_range("Index out of range");
        }
        else
        {
            return _buf[index];
        }
    }
    bool String::operator==(const String &other)
    {
        if (_len != other._len)
        {
            return false;
        }
        else
        {
            return strcmp(_buf, other._buf);
        }
    }
    String String::operator+(const String &other)
    {
        String res;
        if (_buf == nullptr)
        {
            res = other;
        }
        else if (other._buf == nullptr)
        {
            res = *this;
        }
        else
        {
            res._len = _len + other._len;
            res._buf = new char[res._len + 1];
            strcpy(res._buf, _buf);
            strcat(res._buf, other._buf);
        }
        return res;
    }
    std::istream &operator>>(std::istream &is, String &str)
    {
        is >> str._buf;
        return is;
    }
    std::ostream &operator<<(std::ostream &os, const String &str)
    {
        if(str._buf==nullptr)
            os<<"";
        else{
            os<<str._buf;
        }
        return os;
    }
}