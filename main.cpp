#include <iostream>

#include "./src/test.h"
using std::cout;
#include <iostream>
#include <string>
#include <vector>

void test();
int main() { test(); }
void test() {
    const int SIZE = 10;
    PrintMemoryUsage();
    int* test = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        test[i] = i;
    }

    PrintMemoryUsage();
    delete[] test;
    PrintMemoryUsage();
}
