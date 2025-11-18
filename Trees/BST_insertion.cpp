#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    Node* insertNode(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } 
        else {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    // inorder traversal -> sorted output
    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
};

int main() {
    BST tree;

    int data[] = {5, 2, 9, 1, 3, 7, 10};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Inserting data: ";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << endl << endl;

    for (int i = 0; i < n; i++) {
        tree.insert(data[i]);
        cout << "After inserting " << data[i] << ": ";
        tree.inorder(tree.root);
        cout << endl;
    }

    return 0;
}
