#include <iostream>
#include <queue>
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

    // Insert like a simple Binary Tree
    Node* insertNode(Node* root, int val) {
        if (!root) return new Node(val);

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                temp->left = new Node(val);
                break;
            } else q.push(temp->left);

            if (!temp->right) {
                temp->right = new Node(val);
                break;
            } else q.push(temp->right);
        }
        return root;
    }

    void insert(int val) {
        root = insertNode(root, val);
    }

    // BFS Traversal (Level Order)
    void BFS() {
        if (!root) return;

        queue<Node*> q;
        q.push(root);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
};

int main() {
    BinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(30);
    bt.insert(40);
    bt.insert(50);

    bt.BFS();

    return 0;
}