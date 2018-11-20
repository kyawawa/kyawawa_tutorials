// -*- mode: C++; coding: utf-8-unix; -*-

/**
 * @file  union_test.cpp
 * @brief
 * @author Tatsuya Ishikawa
 */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    union testUnion {
        int value;
        std::string name;

        testUnion() : value(0) {}
        ~testUnion() {}
    };

    testUnion test;
    test.value = 2;

    if (test.value == 2) {
        std::cerr << test.value << std::endl;
    }

    // test.name = "NAME";
    // if (test.value != 2) {
        // std::cerr << test.name << std::endl;
    // }

    return 0;
}
