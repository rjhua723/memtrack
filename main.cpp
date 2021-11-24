#include <iostream>
using std::cout;
void shiftLeft(int* arr, const int kArr, int location);
void displayArray(const int* arr, int size);
int main() {
    const int kArr = 10;
    int kArrSize = kArr;
    int* arr = new int[kArr];
    for (int i = 0; i < kArr; i++) {
        arr[i] = i;
    }
    displayArray(arr, kArrSize);
    shiftLeft(arr, kArr, 0);
    kArrSize--;
    displayArray(arr, kArrSize);
    shiftLeft(arr, kArr, kArrSize);
    kArrSize--;
    displayArray(arr, kArrSize);
    return 0;
}
void shiftLeft(int* arr, const int kArr, int location) {
    for (int i = location; i < kArr - 1; i++) {
        arr[i] = arr[i + 1];
    }
}
void displayArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "|";
    }
    cout << "\n";
}
