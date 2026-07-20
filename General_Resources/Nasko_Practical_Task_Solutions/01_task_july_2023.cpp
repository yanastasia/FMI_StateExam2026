#include <iostream>

using namespace std;

// task 1.1
bool isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

char *removeWhitespace(char *str) {
    size_t read = 0, write = 0;

    while (str[read]) {
        if (isWhitespace(str[read])) {
            read++;
        } else {
            str[write++] = str[read++];
        }
    }

    str[write] = '\0';
    return str;
}

// task 1.3 July 2-23
void pass(int* arr, size_t size, bool& swappedAtLeastOnce) {
    if (size <= 1) {
        return;
    }

    if (arr[0] > arr[1]) {
        std::swap(arr[0], arr[1]);
        swappedAtLeastOnce = true;
    }

    pass(arr + 1, size - 1, swappedAtLeastOnce);
}

void bubbleSort(int* arr, size_t size) {
    bool swappedAtLeastOnce = false;
    pass(arr, size, swappedAtLeastOnce);

    if (swappedAtLeastOnce) {
        bubbleSort(arr, size);
    }
}

int main() {
//    char str[] = "Nakso IT \n \t pro  \n";
//    cout << removeWhitespace(str);

    // 02468
//    for (int i = 0; i < 10; ++i) {
//        if (i % 2) continue;
//        cout << i;
//    }

//    int i = 0x10;
//    cout << i; // 16

//    int a = 1, b = 2, c = 3;
//    cout << (a ? b : c); // 2

//    char str[] = "abc";
//    char* p = str;
//    ++p;
//    ++*p;
//    cout << str; // acc

//    int arr[7] = { 5, 3, 8, 1, 13, 15, -5 };
//    bubbleSort(arr, 7);
//    for(int element : arr) {
//        cout << element << " ";
//    }

    int x = 2;
    int arr[] = { 10, 20, 30};
    cout << "\nA: " << 5./x;
    cout << "\nB: " << (x << 4);
    cout << "\nC: " << arr[!x];
    cout << "\nD: " << *(arr+x);
    cout << "\nE: " << (2 + x++);
    // A: 2.5
    // B: 32
    // C: 10
    // D: 30
    // E: 4
}