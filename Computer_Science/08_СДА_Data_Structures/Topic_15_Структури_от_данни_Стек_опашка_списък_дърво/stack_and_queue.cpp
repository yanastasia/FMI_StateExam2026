#include <iostream>
#include <stdexcept>

using namespace std;

const int N = 1000;

class StaticStack {
private:
    int elements[N];
    int count = 0;

public:
    int peek() {
        if (this->empty()) {
            throw underflow_error("There is no elements in the stack");
        }

        return elements[count - 1];
    }

    int pop() {
        if (this->empty()) {
            throw underflow_error("There is no elements in the stack");
        }

        return elements[--count];
    }

    void push(int element) {
        if (count == N) {
            throw overflow_error("There is no enough space in the stack");
        }

        elements[count++] = element;
    }

    bool empty() {
        return count <= 0;
    }
};

class DynamicStack {
private:
    int *elements;
    int count;
    int capacity;

public:
    DynamicStack() {
        this->capacity = 8;
        this->count = 0;
        this->elements = new int[this->capacity];
    }

    DynamicStack(const DynamicStack &stack) {
        this->capacity = stack.capacity;
        this->count = stack.count;

        this->elements = new int[this->capacity];
        for (int i = 0; i < this->count; ++i) {
            this->elements[i] = stack.elements[i];
        }
    }

    DynamicStack &operator=(const DynamicStack &stack) {
        if (this != &stack) {
            delete[] this->elements;
            this->capacity = stack.capacity;
            this->count = stack.count;
            this->elements = new int[this->capacity];
            for (int i = 0; i < this->count; ++i) {
                this->elements[i] = stack.elements[i];
            }
        }

        return *this;
    }

    int peek() {
        if (this->empty()) {
            throw underflow_error("There is no elements in the stack");
        }

        return this->elements[count - 1];
    }

    int pop() {
        if (this->empty()) {
            throw underflow_error("There is no elements in the stack");
        }

        int element = this->elements[count - 1];
        this->count--;
        shrink();

        return element;
    }

    void push(int element) {
        if (this->count == this->capacity) {
            grow();
        }

        this->elements[count++] = element;
    }

    bool empty() {
        return this->count <= 0;
    }

    ~DynamicStack() {
        delete[] this->elements;
    }

private:
    void shrink() {
        if (this->count > this->capacity / 4) {
            return;
        }

        int *newArr = new int[this->capacity / 2];
        for (int i = 0; i < this->count; ++i) {
            newArr[i] = this->elements[i];
        }

        int *temp = this->elements;
        this->elements = newArr;
        delete[] temp;
    }

    void grow() {
        if (this->count < this->capacity) {
            return;
        }

        this->capacity *= 2;
        int *newArr = new int[this->capacity];
        for (int i = 0; i < this->count; ++i) {
            newArr[i] = this->elements[i];
        }

        int *temp = this->elements;
        this->elements = newArr;
        delete[] temp;
    }
};

class Queue {
private:
    struct Node {
        Node *next;
        int data;

        Node() : data(0), next(nullptr) {
        }

        Node(int init_data, Node *init_next = nullptr) : data(init_data), next(init_next) {
        }
    };

    Node *front;
    Node *back;

public:
    Queue() : front(nullptr), back(nullptr) {
    }

    Queue(const Queue& queue) {
        copy(queue);
    }

    Queue& operator=(const Queue& queue) {
        if (this != &queue) {
            freeMemory();
            copy(queue);
        }

        return *this;
    }

    ~Queue() {
        freeMemory();
    }

    bool isEmpty() {
        return this->front == nullptr;
    }

    int peek() {
        if (this->isEmpty()) {
            throw underflow_error("There are no elements in the queue");
        }

        return this->front->data;
    }

    int dequeue() {
        if (this->isEmpty()) {
            throw underflow_error("There are no elements in the queue");
        }

        Node *temp = this->front;
        this->front = this->front->next;

        if (this->front == nullptr) {
            this->back = nullptr;
        }

        int element = temp->data;
        delete temp;
        return element;
    }

    void enqueue(int element) {
        if (isEmpty()) {
            this->front = new Node(element);
            this->back = this->front;
            return;
        }

        this->back->next = new Node(element);
        this->back = this->back->next;
    }

private:
    void copy(const Queue &queue) {
        Node* current = queue.front;
        while (current != nullptr) {
            enqueue(current->data);
            current = current->next;
        }
    }

    void freeMemory() {
        Node *current = this->front;
        while (current != nullptr) {
            Node *next = current->next;
            delete current;
            current = next;
        }

        this->front = nullptr;
        this->back = nullptr;
    }
};

template <typename T>
class Queue {
    T* data;
    int capacity;
    int start;
    int end;
    int size;

    void free() {
        delete[] this->data;
    }

    void copy(const Queue& other) {
        this->data = new T[other.capacity];
        for (int i = 0; i < other.capacity; ++i) {
            this->data[i] = other.data[i];
        }

        this->capacity = other.capacity;
        this->size = other.size;
        this->start = other.start;
        this->end = other.end;
    }

public:
    Queue(int total_capacity = 8) {
        this->capacity = total_capacity;
        this->end = 0;
        this->size = 0;
        this->start = 0;
        this->data = new T[capacity];
    }

    Queue<T>(const Queue<T>& other) {
        copy(other);
    }

    Queue<T>& operator=(const Queue<T>& other) {
        if (this != &other) {
            free();
            copy(other);
        }

        return *this;
    }

    void push(T element) {
        if (this->size == this->capacity) {
            throw logic_error("There is no space in the queue!");
        }

        this->data[this->end++] = element;
        this->size++;
        if (this->end == this->capacity) {
            this->end = 0;
        }
    }

    void pop() {
        if (this->isEmpty()) {
            throw logic_error("There is no elements in the queue");
        }

        this->start++;
        this->size--;
        if (this->start == this->capacity) {
            this->start = 0;
        }
    }

    T peek() {
        if (this->isEmpty()) {
            throw logic_error("There is no elements in the queue");
        }

        return this->data[this->start];
    }

    bool isEmpty() {
        return this->size == 0;
    }
};

int main() {
//    DynamicStack stack;
//    for (int i = 0; i < 100; ++i) {
//        stack.push(i);
//    }
//
//    DynamicStack copy = stack;
//    while (!copy.empty()) {
//        cout << copy.pop() << " ";
//    }
//
//    cout << endl;
//    cout << stack.peek() << endl;
//    stack.pop();
//    copy = stack;
//    while (!copy.empty()) {
//        cout << copy.pop() << " ";
//    }

    Queue queue;
//    queue.enqueue(10);
//    cout << queue.peek() << endl;
//    queue.dequeue();

    for (int i = 0; i < 10; ++i) {
        queue.enqueue(i);
    }

    Queue copy = queue;

    while (!queue.isEmpty()) {
        cout << queue.dequeue() << " ";
    }

    cout << endl;
    while (!copy.isEmpty()) {
        cout << copy.dequeue() << " ";
    }

    copy.enqueue(5);
    copy.enqueue(6);
    copy.enqueue(7);
    copy.enqueue(8);

    cout << endl;
    queue = copy;
    while (!queue.isEmpty()) {
        cout << queue.dequeue() << " ";
    }
}
