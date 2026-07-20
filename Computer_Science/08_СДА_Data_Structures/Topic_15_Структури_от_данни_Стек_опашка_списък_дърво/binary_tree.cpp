#include <iostream>

using namespace std;


class BinaryTree {
private:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    void printInOrder(BinaryTree *tree) {
        if (tree == nullptr) {
            return;
        }

        printInOrder(tree->left);
        cout << tree->value << " ";
        printInOrder(tree->right);
    }

    void printPostOrder(BinaryTree *tree) {
        if (tree == nullptr) {
            return;
        }

        printPostOrder(tree->left);
        printPostOrder(tree->right);
        cout << tree->value << " ";
    }

    void printPreOrder(BinaryTree *tree) {
        if (tree == nullptr) {
            return;
        }

        cout << tree->value << " ";
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }

public:
    BinaryTree(int value, BinaryTree *left = nullptr, BinaryTree *right = nullptr) {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    void printInOrder() {
        printInOrder(this);
    }

    void printPostOrder() {
        printPostOrder(this);
    }

    void printPreOrder() {
        printPreOrder(this);
    }
};

int main() {
    BinaryTree tree(1,
                    new BinaryTree(7,
                                   new BinaryTree(4,
                                                  new BinaryTree(3),
                                                  nullptr),
                                   new BinaryTree(5,
                                                  new BinaryTree(6),
                                                  new BinaryTree(7))));
    tree.printPostOrder();
    cout << endl;
    tree.printPreOrder();
    cout << endl;
    tree.printInOrder();

    // TODO: delete the allocated dynamic memory
}