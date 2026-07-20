#include <iostream>

using namespace std;

bool member(int x, int a[], int size) {
    if (size == 0) return false;
    return a[size / 2] == x ||
           (a[size / 2] < x && member(x, a + size / 2 + 1, size - size / 2 - 1)) ||
           (a[size / 2] > x && member(x, a, size / 2));
}

void selectionSort(int nums[], int N) {
    for (int i = 0; i < N - 1; i++) {
        int min = i;
        for (int j = i + 1; j < N; j++) {
            if (nums[j] < nums[min])
                min = j;
        }

        if (min != i) {
            int x = nums[i];
            nums[i] = nums[min];
            nums[min] = x;
        }
    }
}

void task1_c() {
    int a = 0; int b = 15; int result = 1;
    if (b < 10 && b / a < 10) result = 0;
    else result = 1;

    cout << result;
}

int main() {
    int nums[] = {5, 4, -1, 2, 12, 10, 122, -10};
    selectionSort(nums, 8);
    for (int i = 0; i < 8; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // task1_c();
}


