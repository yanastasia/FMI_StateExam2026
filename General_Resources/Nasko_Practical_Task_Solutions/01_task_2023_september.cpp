#include <iostream>

using namespace std;

// task 1.1 - september 2023
int power(int base, unsigned int power) {
    int result = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            result = result * base;
        }

        base *= base;
        power /= 2;
    }

    return result;
}

// task 1.2 - september 2023
void print_task_1_2() {
    int a = 10, b = 010, c = 0x10;
    cout << a << ", " << b << ", " << c;
    // 10, 8, 16
    // Променливата a е в десетичен формат и има стойност 10.
    // Променливата b е в осмичен формат (започващ с 0) и има стойност 8 (защото 010 в осмична бройна система е равно на 8 в десетична).
    // Променливата c е в шестнадесетичен формат (започващ с 0x) и има стойност 16 (защото 0x10 в шестнадесетична бройна система е равно на 16 в десетична).
}

// task 1.3 - september 2023
void print_task_1_3_1() {
    cout << "while look result: ";
    int var = 0;
    while (var++ < 5)
        cout << var;

    // 12345
}

// task 1.4 - september 2023
void print_task_1_3_2() {
    cout << "do while look result: ";
    int var = 0;
    do {
        cout << var;
    } while (++var < 5);

    // 01234
}

void print_task_1_4() {
    unsigned int x = 0x11335577;
    unsigned char *ptr = (unsigned char *) &x;
    ++*ptr;
    ++*(ptr + 1);
    ++ptr[2];
    ++3[ptr]; // 3[ptr] е същото като *(ptr + 3)
    cout << hex << "0x" << x; // 0x12345678
}

void print_task_1_6() {
    const size_t size = 3;
    char box[size][size] = {
            'a', 'b', 'c',
            'd', 'e', 'f',
            'g', 'h', 'i'
    };

    // Трябва да извежда aei
    for (int i = 0; i < size; i++)
        cout << box[i][i];
    // Трябва да извежда ceg
    for (int i = 0; i < size; i++)
        cout << box[i][size - i - 1];
// Трябва да извежда gec
    for (int i = 0; i < size; i++)
        cout << box[size - i - 1][i];
// Трябва да извежда abcfihgd
    for (int i = 0; i < size; ++i)
        cout << box[0][i];
    for (int i = 1; i < size; i++)
        cout << box[i][size - 1];
    for (int i = size - 2; i >= 0; --i)
        cout << box[size - 1][i];
    for (int i = size - 2; i > 0; --i)
        cout << box[i][0];
}

int main() {
    print_task_1_6();
}