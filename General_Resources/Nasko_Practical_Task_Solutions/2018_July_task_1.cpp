#include <iostream>
#include <string>

using namespace std;

unsigned int countDigits(unsigned int a) {
    int count = 0;
    while (a > 0) {
        a /= 10;
        count++;
    }

    return count;
}

unsigned int getMax(unsigned int a, unsigned int b) {
    return a > b ? a : b;
}

unsigned int getMin(unsigned int a, unsigned int b) {
    return a < b ? a : b;
}

int compareLex(unsigned int a, unsigned int b) {
    if (a == b) {
        return 0;
    }

    unsigned int aCopy = a;
    unsigned int bCopy = b;
    unsigned int aDigits = countDigits(a);
    unsigned int bDigits = countDigits(b);

    while (aDigits > bDigits) {
        aDigits--;
        aCopy /= 10;
    }

    while (bDigits > aDigits) {
        bDigits--;
        bCopy /= 10;
    }

    if (aCopy == bCopy) {
        return a > b ? 1 : -1;
    }

    return aCopy > bCopy ? 1 : -1;
}

void sortLex(unsigned int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (compareLex(arr[i], arr[j]) > 0) {
                unsigned int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    unsigned int arr[] = {5, 2018, 201, 14, 9, 0};
    sortLex(arr, 6);

    for (int i = 0; i < 6; ++i) {
        cout << arr[i] << " ";
    }
}
