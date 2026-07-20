#include <iostream>
#include<vector>
#include <cstring>

using namespace std;

void task1_1() {
    int arr[] = {1, 2, 3};
    cout << (arr[1] == *(arr + 2)) << endl; // false
    cout << (arr == &arr[0]) << endl; // true
    cout << ((arr + 1) == &arr[1]) << endl; // true
    cout << (*arr == arr[0]) << endl; // true;
};

void mystery(const char* str) {
    while(*str && *(str + 1)) {
        cout << *str;
        str += 2;
    }
}

void task_1_2() {
    mystery("abcdef"); // ace
}

void task_1_3() {
    char s1[] = "Hello";
    char s2[] = "world!";
    char result[80];

    // #include <cstring>
    strcpy(result, s1);
    strcat(result, " ");
    strcat(result, s2);

    cout << result;
}

bool g(const char* text, const char* word) {
    if (!*word) {
        return true;
    }
    if (!*text) {
        return false;
    }
    if (*word != *text) {
        return false;
    }

    return g(text + 1, word + 1);
}

bool f(const char* text, const char* word) {
    if (!*word) {
        return true;
    }
    if (!*text) {
        return false;
    }

    return g(text, word) || f(text + 1, word);
}

void task_1_4() {
    cout << f("Nasko IT is testing", "is t");
}

void task_1_5() {
    char arr[3][3] = { 'a', 'b', 'c',
    'd', 'e', 'f',
    'g', 'h', 'i' };
    for (int i = 0; i < 3; ++i)
        std::cout << arr[2-i][i];
    // gec
}

void task_1_6() {
    double var = 5 / 2;
    std::cout << var; // 2
}

int main() {
    // task1_1();
    // task_1_2();
    // task_1_3();
    // task_1_4();
    // task_1_5();
    task_1_6();
}