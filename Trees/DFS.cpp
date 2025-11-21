#include <iostream>
using namespace std;

// Node structure for Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Binary Tree Class
class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(NULL) {}

    // Simple Binary Tree Insert (level-wise)
    Node* insertNode(Node* root, int val) {
        if (!root) return new Node(val);

        if (!root->left)
            root->left = new Node(val);
        else if (!root->right)
            root->right = new Node(val);
        else
            root->left = insertNode(root->left, val);

        return root;
    }

    void insert(int val) {
        root = insertNode(root, val);
    }

    // DFS Traversals

    void preorder(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main() {
    BinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(30);
    bt.insert(40);
    bt.insert(50);

    cout << "Preorder (DFS): ";
    bt.preorder(bt.root);

    cout << "\nInorder (DFS): ";
    bt.inorder(bt.root);

    cout << "\nPostorder (DFS): ";
    bt.postorder(bt.root);

    return 0;
}
