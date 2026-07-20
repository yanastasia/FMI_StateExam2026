#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void str_test() {
    char word[] = {'N', 'a', 's', 'k', 'o', '\0' };
    char name[] = "Nasko IT";

    char test[6] = "Hello";
    cout << strlen(test) << endl;

    char copy[12];
    strcpy(copy, test);
    cout << copy << endl;

    cout << strcmp("ASD", "asd") << endl;
    cout << strcmp("basa", "basd") << endl;
    cout << strcmp("asd", "asd") << endl;
    cout << strcmp("nasko", "asd") << endl;

    char buffer[12] = {};
    strcat(buffer, test);
    strcat(buffer, " ");
    strcat(buffer, word);
    cout << buffer << endl;

    cout << strchr("asd", 's') << endl;
    cout << strchr("asd", 'd') << endl;
    cout << strchr("asd", 'a') << endl;
    // cout << strchr(word, '!') << endl;

    cout << strstr("nasko", "sk") << endl;

//    char b[8] = "Hello,";
//    char a[] = "word!";
//    strcat(b ,a);
//    cout << b;

//    char nonTerminated[4] = {'a', 's', 'd', 'g'};
//    cout << strlen(nonTerminated);
}

void test_multidimensional_arrays() {
    int a[2][3] = { { 1, 2, 3 }, { 4, 5, 6}};
    double b[5][2] = {0.1, 0.2, 0.3 };
    cout << b[2][1] << endl;
}

void test_bitwise() {
    int a = 456;
    cout << (a >> 3) << endl; // a / 2^3

    cout << (a << 3); // a * 2^3
}

int add5(int& a) {
    a+=5;
    return a;
}

void execute(int a, int b, int (*op) (int, int)) {
    cout << op(a, b);
}

int sum(int a, int b) {
    return a + b;
}

void test_functions() {
    int a = 2;
    int b[4] = {1, 2, 3, 4};

    execute(1, 2, sum);
    execute(3, 4, [](int a, int b) { return a + b;});
}

void test_pointers() {
    int x = 5, *p = &x;
    int *q = p, y = *p + 2;
    cout << y << endl;
    *p++;
    cout << *p << endl;
    p = &y;
    *q = 1;
    cout << x << endl;
    *p = *q;
    cout << x << endl;
    cout << y << endl;

    int a[5] = {1 , 2, 3, 4, 5 };
    *a = 15;
    cout << a[0] << endl;
    int t = ++*(a + 4);
    cout << t << " " << a[4] << " " << 2[a] << endl;


    int* const const_prt = &t;
    // const_prt++;
    *const_prt = 10;
    int const * ptr_to_const = &t;
    ptr_to_const++;
    // *ptr_to_const = 20;

    char const* constant = "Hello world";
}

void test_dynamic_memory() {
    int* test = new int(10);
    char* s = new char[6];
    strcpy(s, "hello");
    int c = 5;
    int* p = &c;
    // хвърля грешка по време на изпълнение
    // delete p;

    int * block  = new int[10];
    // хвърля грешка по време на изпълнение
    // delete (block + 2);

    int* ptr = new int[5];
    int* q = ptr;
    delete[] ptr;
//    // Не е позволено използването на памет след като е била освободена
//    q[1] = 5;
//    cout << q[1];

    
}

int main() {
    // str_test();
    // test_multidimensional_arrays();
    // test_pointers();
    test_dynamic_memory();
}