#include <iostream>

using namespace std;

class BinarySearchTree {
private:
    class Node {
    public:
        int value;
        Node *left;
        Node *right;

        Node(int init_value, Node *init_left = nullptr, Node *init_right = nullptr) {
            this->value = init_value;
            this->left = init_left;
            this->right = init_right;
        }
    };

    Node *root;

    Node *findMin(Node *current) {
        if (current->left == nullptr) {
            return current;
        }

        return findMin(current->left);
    }

    Node *findMax(Node *current) {
        if (current->right == nullptr) {
            return current;
        }

        return findMax(current->right);
    }

    void printSorted(Node *current) {
        if (current == nullptr) {
            return;
        }

        printSorted(current->left);
        cout << current->value << " ";
        printSorted(current->right);
    }

    Node *find(Node *current, int value) {
        if (current == nullptr) {
            return nullptr;
        }

        if (current->value == value) {
            return current;
        }
        if (current->value < value) {
            return find(current->right, value);
        }

        return find(current->left, value);
    }

    Node *insert(Node *current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (current->value < value) {
            current->right = insert(current->right, value);
        } else {
            current->left = insert(current->left, value);
        }

        return current;
    }

    Node *remove(Node *current, int value) {
        if (current == nullptr) {
            return nullptr;
        }
        if (current->value < value) {
            current->right = remove(current->right, value);
        } else if (current->value > value) {
            current->left = remove(current->left, value);
        } else {
            if (current->left == nullptr) {
                Node *tmp = current->right;
                delete current;
                return tmp;
            }

            Node *maxNode = findMax(current->left);
            current->value = maxNode->value;
            current->left = remove(current->left, maxNode->value);
        }

        return current;
    }

public:
    BinarySearchTree() {
        this->root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void remove(int value) {
        root = remove(root, value);
    }

    bool exists(int value) {
        return find(root, value) != nullptr;
    }

    void printSorted() {
        printSorted(root);
    }

    int findMin() {
        if (root == nullptr) {
            throw logic_error("The BST is empty");
        }

        return findMin(root)->value;
    }

    int findMax() {
        if (root == nullptr) {
            throw logic_error("The BST is empty");
        }

        return findMax(root)->value;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(8);
    bst.insert(0);
    bst.insert(-5);
    bst.insert(7);
    bst.insert(6);
    bst.insert(10);
    bst.insert(15);
    bst.insert(9);
    bst.insert(2);
    bst.insert(4);
    bst.insert(3);

    cout << "Min" << bst.findMin() << endl;
    cout << "Max" << bst.findMax() << endl;
    cout << "Exists 3" << bst.exists(3) << endl;
    cout << "Exists 1" << bst.exists(1) << endl;

    bst.printSorted();
    cout << endl;

    bst.remove(5);

    bst.printSorted();
}