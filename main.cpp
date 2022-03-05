#include <iostream>

#include "./src/test.h"
using std::cout;
#include <iostream>
#include <string>
struct AllocationMetrics {
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};
static AllocationMetrics s_AllocationMetrics;
static void PrintMemoryUsage() {
    std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage()
              << " bytes\n";
}
void* operator new(size_t size) {
    s_AllocationMetrics.TotalAllocated += size;
    // std::cout << "Allocating " << size " bytes \n";
    return malloc(size);
}
void operator delete(void* memory, size_t size) {
    s_AllocationMetrics.TotalFreed += size;
    // std::cout << "Allocating " << size << " bytes \n";
    free(memory);
}
void test();
int main() { test(); }
void test() {
    const int SIZE = 10;
    int* arr = new int[SIZE];
    PrintMemoryUsage();
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i;
    }
    delete[] arr;
    PrintMemoryUsage();
}
