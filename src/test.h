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
/**
 * @brief this is an overloaded new[] that tracks the allocated size "behind"
 * the pointer
 * @note The void* is manipulated with static_cast to different types. For
 * example, to set the size "behind" the pointer, use a size_t* to set the size
 * allocated. To offset the pointer, use a char* and offset it by how much was
 * allocated "behind" the pointer.
 * @param size The size to allocate. This will be kept track of
 * @return void* A memory address to allocated memory. At index [-1] the size in bytes should be available.
 */
void* operator new[](size_t size) {
    s_AllocationMetrics.TotalAllocated += size;
    void* p = malloc(sizeof(size) + size);
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
