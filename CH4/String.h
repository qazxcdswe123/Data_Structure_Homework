//
// Created by yn on 26/10/2022.
//

#ifndef CH3_STRING_H
#define CH3_STRING_H

#include <iostream>

class String {
    friend String operator+(const String &s1, const String &s2);

    friend std::ostream &operator<<(std::ostream &os, const String &obj);

    friend std::istream &operator>>(std::istream &is, String &obj);

    friend bool operator>(const String &s1, const String &s2);

    friend bool operator>=(const String &s1, const String &s2);

    friend bool operator==(const String &s1, const String &s2);

    friend bool operator!=(const String &s1, const String &s2);

    friend bool operator<(const String &s1, const String &s2);

    friend bool operator<=(const String &s1, const String &s2);

private:
    size_t len;
    char *data;

public:
    explicit String(const char *s = "");

    String(const String &other);

    String &operator+=(const String &other);

    String &operator=(const String &other);

    String operator()(int start, int end);

    const char &operator[](int index) const;

    ~String();

    size_t getLen() const;

    int find(const char *pattern); // use KMP algorithm for pattern searching

    int naiveFind(const char *pattern); // use naive algorithm for pattern searching
};


#endif //CH3_STRING_H
