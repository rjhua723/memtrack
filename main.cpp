#include <iostream>
using std::cout;
void test(int current, int* walker);
int main() {
    const int kArr = 10;
    int* arr = new int[kArr];
    test(kArr, arr);
    for (int i = 0; i < kArr; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
}
void test(int current, int* walker) {
    if (current > 0) {
        *walker = current;
        test(current - 1, walker + 1);
    }
}
