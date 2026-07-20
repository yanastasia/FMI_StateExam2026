#include <iostream>
#include <queue>

using namespace std;

struct Node {
    char text;
    Node *left, *right;
};

int getDepth(Node *root) {
    if (root == nullptr) {
        return 0;
    }

    return max(1 + getDepth(root->left), 1 + getDepth(root->right));
}

Node* createTempNode(vector<Node*>& temp_nodes) {
    Node *temp_node = new Node;
    temp_node->left = nullptr;
    temp_node->right = nullptr;
    temp_node->text = ' ';
    temp_nodes.push_back(temp_node);
    return  temp_node;
}

void printText(Node *root) {
    Node *delimiter = nullptr;
    queue<Node *> q;
    q.push(root);
    q.push(delimiter);
    vector<Node *> temp_nodes;
    int depth = getDepth(root);

    while (!q.empty() && depth > 0) {
        while (q.front() != nullptr && !q.empty()) {
            Node *temp = q.front();
            q.pop();

            cout << temp->text;
            q.push(temp->left == nullptr ? createTempNode(temp_nodes) : temp->left);
            q.push(temp->right == nullptr ? createTempNode(temp_nodes) : temp->right);
        }

        depth--;
        q.pop();
        cout << endl;
        q.push(delimiter);
    }

    for(Node* temp: temp_nodes) {
        delete temp;
    }
}

int main() {
    Node *root = new Node{
            'I',
            left: new Node{
                    'a',
                    left: new Node{
                            'g',
                            left: new Node{
                                    'a',
                                    left: new Node{
                                            'n',
                                            left: new Node{
                                                    's'
                                            }
                                    },
                                    right: new Node{
                                            'g',
                                            right: new Node{
                                                    '!'
                                            }
                                    }
                            },
                            right: new Node{
                                    't',
                                    right: new Node{
                                            'p'
                                    }
                            }
                    },
                    right: new Node{
                            'o',
                            right: new Node{
                                    's',
                                    left: new Node{
                                            'r'
                                    },
                                    right: new Node{
                                            'o'
                                    }
                            }
                    }
            },
            right: new Node{
                    'm',
                    left: new Node{
                            'o',
                            left: new Node{
                                    'o',
                                    left: new Node{
                                            'b'
                                    },
                                    right: new Node{
                                            'l'
                                    }
                            },
                            right: new Node{
                                    'l',
                                    left: new Node{
                                            'e'
                                    },
                                    right: new Node{
                                            'm'
                                    }
                            }
                    },
                    right: new Node{
                            'd',
                            left: new Node{
                                    'v'
                            },
                            right: new Node{
                                    'i'
                            }
                    }
            }
    };

    printText(root);
}


