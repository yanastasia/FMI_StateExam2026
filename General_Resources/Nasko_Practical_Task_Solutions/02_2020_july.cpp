#include <iostream>
#include<vector>
#include <cstring>

using namespace std;

struct test {
    static int var;
    test() {
        var = 5;
    }
};

int test::var = 0;

void task_2_1() {
    cout << '(' << test::var << ')';
    test obj1;
    obj1.var = 10;
    test obj2;
    cout << '-' << test::var << '-';

    // (0)-5-
}

class virtualClass {
public:
    virtual void f() = 0;

    virtual ~virtualClass() { };
};

template <typename T>
class Array {
    static const size_t size = 10;
    T data[size];

public:
    T& at(size_t index) {
        if (index >= size) {
            throw std::out_of_range("error");
        }

        return data[index];
    }
};

void task_2_7() {
    Array<int> a;
    a.at(0) = 5;
    cout << a.at(0);

    Array<Array<int>> b;
    b.at(0) = a;
    cout << b.at(0).at(0);
}

int main() {
    // task_2_1();
    task_2_7();
}