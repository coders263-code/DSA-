#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) { 
        data = val; 
        left = right = nullptr; }
};

// Function to build tree dynamically
Node* buildTree() {
    int val;
    cout << "Enter value (-1 for no node): ";
    cin >> val;

    if(val == -1) return nullptr;

    Node* root = new Node(val);
    cout << "Insert left child of " << val << endl;
    root->left = buildTree();
    cout << "Insert right child of " << val << endl;
    root->right = buildTree();
    return root;
}

// Simple inorder traversal
void inorder(Node* root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = buildTree();
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    return 0;
}