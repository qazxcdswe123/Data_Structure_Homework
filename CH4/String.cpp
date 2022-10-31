//
// Created by yn on 26/10/2022.
//
// This is an old homework, only pattern searching algorithm is newly added.

#include <cstring>
#include <stdexcept>

#include "String.h"

String::String(const char *s) {
    if (s) {
        len = strlen(s);
        data = new char[len + 1];
        strcpy(data, s);
    } else {
        len = 0;
        data = new char[1];
        data[0] = '\0';
    }
}

String::String(const String &other) {
    len = other.len;
    data = new char[len + 1];
    strcpy(data, other.data);
}

String::~String() {
    free(data);
}

String &String::operator+=(const String &other) {
    size_t l = len + other.len;
    char *s = new char[l + 1];
    strcpy(s, data);
    delete[] data;
    strcat(s, other.data);
    return *this;
}

String &String::operator=(const String &other) {
    if (this != &other) {
        if (len != other.len) {
            delete[] data;
            len = other.len;
            data = new char[len + 1];
        }
        strcpy(data, other.data);
    }
    return *this;
}

String String::operator()(int start, int end) {
    String s;
    try {
        if (end < start || end > len || start < 0) {
            throw std::invalid_argument("Error: Invalid argument");
        }
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return static_cast<String>(nullptr);
    }

    int l = end - start;
    s.len = l;
    s.data = new char[len + 1];
    for (int i = 0; i < l; i++) {
        s.data[i] = data[i + start];
    }
    return s;
}

const char &String::operator[](int index) const {
    return data[index];
}

std::ostream &operator<<(std::ostream &os, const String &obj) {
    os << "The length of the String is " << obj.len << std::endl;
    os << "The data of the String is ";
    for (int i = 0; i < obj.len; i++) {
        os << obj.data[i];
    }
    os << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, String &obj) {
    // // Character read or EOF
    // int c = 0;
    // int len = 0;
    // char *s = new char[1];

    // while ((c = fgetc(stdin)) != '\r' && c != '\n' && c != EOF)
    // {
    //     ++len;
    //     char *temp = new char[len + 1];

    //     // copy original value
    //     for (int i = 0; i < len - 1; i++)
    //     {
    //         temp[i] = s[i];
    //     }

    //     temp[len - 1] = c;
    //     delete[] s;
    //     s = temp;
    // }

    //     int wordSize = 64;
    //     int time = 1; // the amount of time it iterate
    //     char *head = new char[wordSize];
    //     char c;
    //     int len = 0;
    //     while (c = getchar() != '\n')
    //     {
    //         if (len == wordSize * time - 1)
    //         {
    //             time++;
    //             char *temp = new char[wordSize * time];
    //             for (int i = 0; i < len; i++)
    //             {
    //                 temp[i] = head[i];
    //             }
    //             delete[] head;
    //             head = temp;
    //         }
    //         head[len++] = c;
    //     }
    //     obj.len = len;
    //     obj.data = new char[len + 1];
    //     // strcpy(obj.data, head);
    //     for (int i = 0; i < len; i++)
    //     {
    //         obj.data[i] = head[i];
    //     }

    //     delete[] head;
    //     return is;

    char s[1000] = {0};
    is >> s;
    strcpy(obj.data, s);
    obj.len = strlen(obj.data);
    return is;
}

bool operator>(const String &s1, const String &s2) {
    int res = strcmp(s1.data, s2.data);
    return res > 0;
}

bool operator>=(const String &s1, const String &s2) {
    int res = strcmp(s1.data, s2.data);
    return res >= 0;
}

bool operator==(const String &s1, const String &s2) {
    int res = strcmp(s1.data, s2.data);
    return res == 0;
}

bool operator!=(const String &s1, const String &s2) {
    int res = strcmp(s1.data, s2.data);
    return res != 0;
}

bool operator<(const String &s1, const String &s2) {
    int res = strcmp(s1.data, s2.data);
    return res < 0;
}

bool operator<=(const String &s1, const String &s2) {
    int res = strcmp(s1.data, s2.data);
    return res <= 0;
}

size_t String::getLen() const {
    return len;
}

int String::find(const char *pattern) {
    /*
     * KMP Algorithm
     * Input: s (length n), pattern (length m)
     * Worst case: O(n + m)
     * Best case: O(m)
     * Average case: O(n + m)
     */
    size_t n = len;
    size_t m = strlen(pattern);
    int *next = new int[m];
    next[0] = -1;
    int j = 0;
    int k = -1;
    while (j < m - 1) {
        if (k == -1 || pattern[j] == pattern[k]) {
            j++;
            k++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
    j = 0;
    k = 0;
    while (j < n && k < m) {
        if (k == -1 || data[j] == pattern[k]) {
            j++;
            k++;
        } else {
            k = next[k];
        }
    }
    delete[] next;
    if (k == m) {
        return j - k;
    } else {
        return -1;
    }
}

String operator+(const String &s1, const String &s2) {
    String s;
    s.len = s1.len + s2.len;
    s.data = new char[s.len + 1];
    strcpy(s.data, s1.data);
    strcat(s.data, s2.data);
    return s;
}

int String::naiveFind(const char *pattern) {
    /*
     * Naive Algorithm
     * Input: s (length n), pattern (length m)
     * Worst case: O(n * m)
     * Best case: O(m)
     * Average case: O(n * m)
     */
    size_t n = len;
    size_t m = strlen(pattern);
    for (int i = 0; i < n - m + 1; i++) {
        int j = 0;
        for (; j < m; j++) {
            if (data[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}