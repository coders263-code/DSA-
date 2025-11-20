#include <iostream>
using namespace std;

// Simple Binary Tree Node
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

    // Insert like a simple Binary Tree (Not BST)
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

    // Convert Binary Tree to Array
    void toArray(Node* root, int arr[], int& i) {
        if (!root) return;
        arr[i++] = root->data;
        toArray(root->left, arr, i);
        toArray(root->right, arr, i);
    }
};

// Heap Class
class Heap {
public:
    // Heapify function
    void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Heap Sort
    void sort(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

int main() {
    BinaryTree bt;
    bt.insert(40);
    bt.insert(10);
    bt.insert(20);
    bt.insert(30);
    bt.insert(50);

    int arr[20];
    int index = 0;

    bt.toArray(bt.root, arr, index);

    cout << "Binary Tree to Array: ";
    for (int i = 0; i < index; i++) cout << arr[i] << " ";

    Heap h;
    h.sort(arr, index);

    cout << "\nSorted (Heap Sort): ";
    for (int i = 0; i < index; i++) cout << arr[i] << " ";

    return 0;
}