#include <iostream>
#include<vector>

using namespace std;

template <typename T>
class Function
{
public:
    virtual T value(T) const = 0;
};

class Inc : public Function<double> {
public:
    double value(double x) const override {
        return x + 1;
    }
};

class Square : public Function<double> {
    double value(double  x) const override {
        return x * x;
    }
};

template <typename T>
class Max : public Function<T> {
private:
    std::vector<Function<T>*> functions;

public:
    void addFunction(Function<T>* f) {
        functions.push_back(f);
    }

    T value(T x) const override {
        if (functions.empty()) {
            throw "Function list is empty!";
        }

        T result = functions[0]->value(x);
        for(size_t i = 1; i < functions.size(); i++) {
            T currentValue = functions[i]->value(x);
            // result = std::max(result, currentValue);
            if (currentValue > result) {
                result = currentValue;
            }
        }

        return result;
    }
};

template <typename T>
class Sum : public Function<T> {
private:
    std::vector<Function<T>*> functions;

public:
    void addFunction(Function<T>* f) {
        functions.push_back(f);
    }

    T value(T x) const override {
        T result = 0;
        for(const Function<T>* fn : functions) {
            result += fn->value(x);
        }

        return result;
    }
};

int main() {
    Inc i; Square sq; Sum<double> s;
    // (x + 1) + (x * x)
    s.addFunction(&i); s.addFunction(&sq);

    Max<double> m;
    // {x + 1, x *x, (x + 1) + (x * x)}
    m.addFunction(&i);
    m.addFunction(&sq);
    m.addFunction(&s);

    double x;
    cin >> x;
    cout << m.value(x) << endl;
}