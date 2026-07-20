#include <iostream>
#include<vector>
#include <cstring>

using namespace std;

void print(int* arr, int size) {
    for(int i = 0; i < size; ++i)
        cout << arr[i] << ";";
    cout << "\n";
}

void task_1_1() {
    const int size = 5;
    int arr[] = { 5, 10, -1, 5, 6};
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j < size; ++j) {
            if (arr[j - 1] < arr[j]) {
                swap(arr[j - 1], arr[j]);
            }
        }
    }

    print(arr, size);
}

char toUpper(char c) {
    return c >= 'a' && c <= 'z' ? c - 'a' + 'A' : c;
}

bool isEven(unsigned int);

bool isOdd(unsigned int n) {
    if (n == 0) return false;
    if (n == 1) return true;

    return isEven(n - 1);
}

bool isEven(unsigned int n) {
    if (n == 0) return true;
    if (n == 1) return false;

    return isOdd(n -1);
}

void task_1_4() {
    for(int i = 0; i < 9; i++)
        cout << (1 << i) << ";";

    cout << endl;

    switch (5 % 2) {
        case 0:
            cout << "0";
        case 1: cout << "1";
        default:
            cout << "x";
    }

    cout << endl;

    for (int i = 0; i < 5; ++i) {
        if (!(i - 3))
            continue;
        std::cout << i;
    }

    cout << endl;
    int arr[] = { 1, 2, 3, 4, 0 };
    *(arr + 2) *= 10;
    for(int* p = arr; *p; p++) {
        cout << *p << ";";
    }
}

int main() {
    task_1_4();
}