#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Fruit {
public:
    virtual void printColor() const = 0;

    virtual Fruit *clone() = 0;

    virtual ~Fruit() {}
};

class Apple : public Fruit {
public:
    void printColor() const override {
        cout << "Red or green" << endl;
    }

    Fruit *clone() override {
        return new Apple(*this);
    }
};

class Orange : public Fruit {
public:
    void printColor() const override {
        cout << "Orange" << endl;
    }

    Fruit *clone() override {
        return new Orange(*this);
    }
};

class Lemon : public Fruit {
public:
    void printColor() const override {
        cout << "Yellow" << endl;
    }

    Fruit *clone() override {
        return new Lemon(*this);
    }
};

class FruitStore {
private:
    Fruit **data;
    size_t size;
    size_t capacity;

    void free() {
        for (int i = 0; i < size; ++i) {
            delete data[i];
        }

        delete[] data;
    }

    void copyFrom(const FruitStore &other) {
        this->capacity = other.capacity;
        this->size = other.size;
        data = new Fruit *[other.capacity];
        for (int i = 0; i < other.size; ++i) {
            data[i] = other.data[i]->clone();
        }
    }

    void resize() {
        this->capacity *= 2;
        Fruit** newData = new Fruit*[this->capacity];
        for (int i = 0; i < this->size; ++i) {
            newData[i] = this->data[i];
        }

        delete[] this->data;
        this->data = newData;
    }

public:
    FruitStore() : size(0), capacity(8) {
        data = new Fruit *[this->capacity];
    }

    FruitStore(const FruitStore &other) {
        copyFrom(other);
    }

    FruitStore &operator=(const FruitStore &other) {
        if (this != &other) {
            free();
            copyFrom(other);
        }

        return *this;
    }

    ~FruitStore() {
        free();
    }

    void addFruit(Fruit *fruit) {
        if (size == capacity) {
            resize();
        }

        this->data[size++] = fruit->clone();
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            this->data[i]->printColor();
        }
    }
};


int main() {
    FruitStore store;
    for (int i = 0; i < 30; ++i) {
        if (i % 3 == 0) {
            Orange orange;
            store.addFruit(&orange);
        }
        else if (i % 3 == 1) {
            Apple apple;
            store.addFruit(&apple);
        }
        else if (i % 3 == 2) {
            Lemon lemon;
            store.addFruit(&lemon);
        }
    }

    store.print();
}

