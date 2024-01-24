# About
This is a very simple C++ header file to track memory allocations and notify of any memory leaks. This works by overriding the new and delete operators and additionally works with new arrays with a given size.

# Usage
Include memtrack.h in your code, which should override the new and delete operators. Alternatively, include memtrack.h as a CMake library and include it in your code. Then call PrintMemoryUsage() in your program to display the total memory allocated in bytes to the console. Placing the function at the end of code should show 0 bytes used if all allocations are accounted for.

The information is stored in the AllocationMetrics struct, which has variables tracking memory freed and memory allocated that can be obtained and used however you want.
A test program is provided in main.cpp that intentionally creates a memory leak with an integer array by not deleting it. There is also a standard vector used that demonstrates the header file's ability to track standard library memory allocations. The test program is built using CMake and gcc, but supports any C++ compilers that CMake supports.

# More Information
Further reading and resources used are provided in the memtrack.h comments in the @note sections.