// -*- mode: C++; coding: utf-8-unix; -*-

/**
 * @file  function.cpp
 * @brief Can change member variables with lambda function as an argument?
 * @author Tatsuya Ishikawa
 */

#include <iostream>
#include <functional>

using namespace std;

class numbers {
private:
    int num1;
    int num2;

public:
    numbers(int i, int j) : num1(i), num2(j) {};

    void addNum1(int i) { num1 += i; }
    void printNums() { cout << "num1: " << num1 << ", num2: " << num2 << endl; }
};


void changeState(function<void()> add_one)
{
    add_one();
}

int main(int argc, char **argv)
{
    numbers nums(0, 1);
    nums.printNums();
    // changeState([=] { nums.addNum1(1); }); // Error: const numbers as this
    changeState([&] { nums.addNum1(1); });
    nums.printNums();
    return 0;
}
