#include <iostream>

using std::cout;

class test {
public:
    int var;

    test() {
        cout << "test()\n"; var = 0;
    }

    test &operator=(const test &other) {
        if (this != &other) {
            cout << "copy\n";
            var = other.var;
        }
        else {
            cout << "self-assignment\n";
        }

        return *this;
    }

    static test& instance() {
        static test obj;
        cout << &obj << std::endl;
        return obj;
    }

    test& self() {
        return *this;
    }

    void _oncreate() {
        cout << "_oncreate()\n";
    }

    void _oncopy() { cout << "_oncopy()\n"; }

    ~test() {
        cout << "desrtruct" << std::endl;
    }
};

void testFn() {
    static test nasko;
    cout << &nasko << std::endl;
};

void task_2_1() {
    test &r1 = test::instance(); // test()
    test &r2 = test::instance(); // нищо
    r1.var = 10; // нищо
    cout << r2.var << "\n"; // 10
    r1.self() = r2; // self-assignment
    new test[3]; // test() * 3
}

class foo {
public:
    // foo() {}

    foo(int) {}
};

void g(foo) {

}

void f (int) {

}

int main() {
    // task_2_1();
    testFn();
    testFn();
    testFn();

    g(5);
    // f(foo(5));
    foo('a');
    // foo objs[5];
}