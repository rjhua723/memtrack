#include <iostream>
#include <string>
#include <vector>

#include "./src/memtrack/memtrack.h"
using std::cout;

void test();
int main() {
    test();
    PrintMemoryUsage();
}
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

    std::vector<int> vTest = {1, 1, 7, 7, 8};
    PrintMemoryUsage();
    for (int i = 0; i < 10; i++) {
        vTest.push_back(i);
        PrintMemoryUsage();
    }
}
