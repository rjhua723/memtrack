#ifndef SRC_TEST_H_
#define SRC_TEST_H_
#include <cstdlib>
#include <iostream>
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
void* operator new[](size_t size) {
    s_AllocationMetrics.TotalAllocated += size;
    void* p = malloc(size + sizeof(size));
    static_cast<size_t*>(p)[0] = size;
    p = static_cast<char*>(p) + sizeof(size);
    return p;
}
void operator delete(void* memory, size_t size) {
    s_AllocationMetrics.TotalFreed += size;
    // std::cout << "Allocating " << size << " bytes \n";
    free(memory);
}
void operator delete[](void* memory) {
    memory = static_cast<char*>(memory) - sizeof(size_t);
    s_AllocationMetrics.TotalFreed += static_cast<size_t*>(memory)[0];
    free(memory);
}
#endif  // SRC_TEST_H_
