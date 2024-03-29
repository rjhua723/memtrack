#ifndef SRC_MEMTRACK_MEMTRACK_H_
#define SRC_MEMTRACK_MEMTRACK_H_

#include <iostream>
#include <cstdlib>
#include <cstdint>

/*
    Code structure based on: https://youtu.be/sLlGEUO_EGE with some changes to
   handle array allocations
*/

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
 * @brief this is an overloaded new[] that saves the allocated size "behind"
 * the pointer
 * @note Idea from: https://stackoverflow.com/a/49793058: The void* is
 * manipulated with static_cast to different types to allow moving the base
 * address. For example, to save the size "behind" the pointer, use a size_t* to
 * save the size allocated. To offset the pointer, use a char* and offset to the
 * right by how much was allocated "behind" the pointer - basically offset it by
 * the size of size_t. A char* is used because pointer arithmetic (offset to
 * right) doesn't exist with a void*.
 * @param size The size to allocate. This will be tracked in AllocationMetrics
 * @return void* A memory address to allocated memory. At index [-1] of
 * appropriate array type (same size as a char*) the size in bytes should be
 * available.
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
/**
 * @brief This deletes an allocated array and tracks memory freed
 * @note This tracks memory by checking "behind" the void pointer (memory) by
 * casting it to a char*, then a size_t*.
 * @param memory The base memory address
 */
void operator delete[](void* memory) {
    memory = static_cast<char*>(memory) - sizeof(size_t);
    s_AllocationMetrics.TotalFreed += static_cast<size_t*>(memory)[0];
    free(memory);
}
void operator delete[](void* memory, size_t size) {
    s_AllocationMetrics.TotalFreed += size;
    free(memory);
}
#endif  // SRC_MEMTRACK_MEMTRACK_H_
