#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

bool isRowSorted(char *a[3][3], int row, int cols) {
    for (int i = 1; i < cols; ++i) {
        if (strcmp(a[row][i - 1], a[row][i]) > 0) {
            return false;
        }
    }

    return true;
}

void printPasswordElement(const char *subject) {
    int count = 0;
    while (*subject != '\0') {
        if (*subject == ' ') {
            if (count > 0) {
                cout << count << " ";
            }

            count = -1;
        }

        count++;
        subject++;
    }

    if (count > 0) {
        cout << count << " ";
    }
}

void revealPassword(char *a[3][3], int m, int n) {
    for (int i = 0; i < m; ++i) {
        if (isRowSorted(a, i, n)) {
            char *targetSubject = a[i][(n - 1) / 2];
            printPasswordElement(targetSubject);
        }
    }
}

// ex 2
struct Node {
    int value;
    Node *next;
    Node *jump;

    Node(int _value) : value(_value), next(nullptr), jump(nullptr) {
    }
};

class JumpLinkedList {
    Node *head;
    Node *tail;
    Node *prevJump;
    int size;
    int k;

public:
    JumpLinkedList() : head(nullptr), tail(nullptr), prevJump(nullptr) {
        this->size = 0;
    }

    void push_back(int value) {
        if (this->head == nullptr) {
            this->head = new Node(value);
            this->tail = this->head;
            this->size++;
            this->prevJump = this->head;
            this->k = 1;
            return;
        }

        Node *newNode = new Node(value);
        this->tail->next = newNode;
        this->tail = newNode;

        if (size % k == 0) {
            this->prevJump->jump = newNode;
            this->prevJump = newNode;
        }

        this->size++;
    }

    bool search(int value) const {
        Node *current = this->head;
        Node *prev = nullptr;
        while (current != nullptr) {
            if (current->value == value) {
                return true;
            }
            if (current->value > value) {
                break;
            }

            if (current->jump != nullptr) {
                prev = current;
            }

            current = current->next;
        }

        while (prev != nullptr) {
            if (prev->value == value) {
                return true;
            }
            if (prev->value > value) {
                return false;
            }

            prev = prev->next;
        }

        return false;
    }

    void readList(const char* fileName) {

        ifstream file(fileName);
        if (!file.is_open()) {
            throw invalid_argument("Can find the file");
        }

        int num;
        int count = 0;
        while (!file.eof()) {
            file >> num;
            count++;
        }

        file.seekg(0, ios::beg);
        this->k = ceil(sqrt(count));

        while (!file.eof()) {
            file >> num;
            this->push_back(num);
        }
    }
};

int main() {
//    // 20 / 30
//    char* arr[3][3] = {
//            "Algebra", "Analitichan Geometriq", "Matematicheksi Analiz",
//            "Увод в програмирането", "Обектно-ориентирано програмиране", "Структури от данни и програмиране",
//            "Bazi ot danni", "Izkusten Intelekt", "JavaScript"
//    };
//
//    revealPassword(arr, 3, 3);

    JumpLinkedList list;
    const char* fileName = "C:\\Users\\Atanas.Vasilev\\Downloads\\nums.txt";
    list.readList(fileName);
    cout << list.search(6);
}


