#include <iostream>

using namespace std;

class LinkedList {
    struct Node {
        int data;
        Node *next;

    public:
        Node() {
            this->data = 0;
            this->next = nullptr;
        }

        Node(int data, Node *next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };

private:
    Node *head;
    Node *tail;
    int count;

public:
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
    }

    void push_back(int value) {
        Node *current = new Node(value);
        this->count++;
        if (head == nullptr) {
            head = current;
            tail = current;
            return;
        }

        this->tail->next = current;
        this->tail = current;
    }

    void push_front(int value) {
        Node *node = new Node(value);
        this->count++;
        if (this->head == nullptr) {
            this->head = node;
            this->tail = node;
            return;
        }

        node->next = this->head;
        this->head = node;
    }

    void forEach(void (*action)(int)) const {
        Node *node = this->head;
        while (node != nullptr) {
            action(node->data);
            node = node->next;
        }

        cout << endl;
    }

    void insert(int number, int position) {
        if (position < 0 || position >= count) {
            return;
        }

        if (position == 0) {
            push_front(number);
            return;
        }

        Node *previousNode = findNode(position - 1);
        Node *newNode = new Node(number);
        this->count++;
        newNode->next = previousNode->next;
        previousNode->next = newNode;

        if (tail == previousNode) {
            this->tail = newNode;
        }
    }

    void pop_front() {
        if (this->head == nullptr) {
            return;
        }

        if (this->head == this->tail) {
            this->tail = nullptr;
        }

        Node *temp = this->head;
        this->head = this->head->next;

        delete temp;
        this->count--;
    }

    void pop_back() {
        if (this->head == nullptr) {
            return;
        }

        if (this->head == this->tail) {
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            Node* prevNode = findNode(this->count - 2);
            Node* temp = this->tail;
            prevNode->next = nullptr;
            this->tail = prevNode;
            delete temp;
        }

        this->count--;
    }

    void remove(int position) {
        if (this->head == nullptr) {
            return;
        }

        if (position == 0) {
            pop_front();
            return;
        }

        Node* current = this->head;
        Node* previous = nullptr;
        for (int i = 0; i < position; ++i) {
            previous = current;
            current = current->next;

            if (current == nullptr) {
                return;
            }
        }

        previous->next = current->next;
        if (current == this->tail) {
            this->tail = previous;
        }

        delete current;
        this->count--;
    }

    int getCount() const {
        return count;
    }

    bool search(int number) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == number) {
                return true;
            }

            current = current->next;
        }

        return false;
    }

private:
    Node *findNode(int position) {
        Node *current = head;
        for (int i = 0; i < position; ++i) {
            if (current == nullptr) {
                return nullptr;
            }

            current = current->next;
        }

        return current;
    }
};

void printNumber(int number) {
    cout << number << " ";
}

int main() {
    LinkedList linkedList;
    linkedList.push_back(1);
    linkedList.push_back(3);
    linkedList.pop_front();
    linkedList.forEach(printNumber);
}