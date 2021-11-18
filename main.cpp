#include <iostream>
// #include <cmath>
// #include <fstream>
// #include <ostream>
// #include <stdlib.h>

using namespace std;

// void secondorminutes() {
//     for (int i = 0; i < 240; i++) {
//         cout << i / 60 << "\n";
//         cout << i % 60 << "\n";
//         if (i / 60 == 1) {
//             incrementHours();
//             i = 0;
//         }
//     }
// }
// void hours() {
//     for (int i = 0; i < 240; i++) {
//         cout << i / 24 << "\n";
//         cout << i % 24 << "\n";
//     }
// }
// void decrementBCD() {
//     cout << "Running decrement \n";
//     int high = 0;
//     int low = 0;
//     for (int i = 0; i < pow(2, 8); i++) {
//         int temp = high * 10 + low;
//         temp--;
//         if (abs(temp) >= 100) {
//             temp = 0;
//         }
//         high = (temp / 10);
//         low = temp % 10;
//         cout << "High:" << abs(high) << " Low:" << abs(low) << "\n";
//     }
// }
// void incrementBCD() {
//     cout << "Running increment \n";
//     int high = 0;
//     int low = 0;
//     for (int i = 0; i < pow(2, 8); i++) {
//         int temp = high * 10 + low;
//         temp++;
//         if (abs(temp) >= 100) {
//             temp = 0;
//         }
//         high = (temp / 10);
//         low = temp % 10;
//         cout << "High:" << abs(high) << " Low:" << abs(low) << "\n";
//     }
// }
// void testBCD() {
//     decrementBCD();
//     // incrementBCD();
// }
// void hours() {
//     int hoursH;
//     int hoursL;
//     for (int hours = 0; hours < 96; hours += 10 + ((4 - (hours % 10)) *
//     (hours) / 30)) {
//         hoursH = (hours % 24) / 10;
//         hoursL = (hours % 24) % 10;
//         cout << "HoursH: " << hoursH << " HoursL: " << hoursL << "\n";
//     }
// }
// /**
//  * @brief
//  *
//  */
// class pizza {
//     public:

//     private:
//     int sauce;
//     int pepperoni;
//     int cheese;
// };
// int test_first();


// class test {
//  public:
//     test();
//     void first();
//     int* getStore();
//  private:
//     int store;
// };

// int* test::getStore() {
//     return &store;
// }
// void test::first() {
//     std::cout << "Run first function of test class\n";
// }
// test::test():store(0) {
// }

int main() {
    // test newStore;
    // std::cout << *newStore.getStore() << "\n";
    // *newStore.getStore() = 5;
    // std::cout << *newStore.getStore() << "\n";
    // const int kArr = 20;
    // int* arr = new int[kArr];
    // for (int i = 0; i < kArr; i++) {
    //     arr[i] = i;
    // }
    // delete arr;
    // for (int i = 0; i < kArr; i++) {
    //     arr[i] = i;
    // }
    // hours();
    // testBCD();
    // // seconds & minutes
    // secondorminutes();
    // // 24 hours
    // hours();
    // int foo;
    // foo = 10;
    // double result;
    // result = static_cast<double>(foo) / 7;
    // const int input = 100;
    // int test = 0;
    // std::cout << test << "\n";
    // const int n = 3;
    // ofstream outStream;
    // ifstream inStream;
    // inStream.open("input.txt");
    // if (inStream.fail()) {
    //     std::cout << "Opening input file failed\n";
    // }
    // outStream.open("outStream.txt");
    // if (outStream.fail()) {
    //     std::cout << "Opening output file failed\n";
    // }
    // for (int i = 0; i < 10; i++) {
    //     outStream << i << ' ';
    // }
    // outStream.close();
    // inStream.close();
    // if (true) {

    // } else if (true) {

    // }
    // test_first();
    // for (int i = 0; i < 5; i++) {
    //   std::cout << "Test\n";
    // }
    // // vector<int> a;
    // int count;
    // if (count) {
    //   std::cout << "Hi\n";
    // }
    // return 0;
    // char *x = (char*)malloc(10 * sizeof(char*));
    // free(x);
    // return x[5];
}
// void test(int z) {
//   if (z == 0)
//     int x = 1 / z;  // warn
// }
// void test() {
//   int i, a[10];
//   int x = a[i]; // warn: array subscript is undefined
// }
// void test() {
//   int x;
//   x |= 1; // warn: left expression is uninitialized
// }
// void test() {
//   int x;
//   if (x) // warn
//     return;
// }
// void test() {
//   int *p = new int;
// } // warn

// int test_first() {
//   void *x = malloc(2);
//   x = 0; // Memory leak
//   return 0;
// }
// class C {
// public:
//   void f();
// };

// void test() {
//   C *pc = 0;
//   pc->f(); // warn: object pointer is null
// }

// class C {
// public:
//   int x;
// };

// void test() {
//   C *pc = 0;
//   int k = pc->x; // warn
// }
