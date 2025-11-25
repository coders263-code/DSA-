1️⃣ Node

Definition: The basic unit of a tree. Each node stores data and pointers to its child nodes.

Example:

A node holds a value.

A node can have 0 or more children.

C++ Code (Node structure):

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int main() {
    Node* root = new Node(10); // root node
    root->left = new Node(5);
    root->right = new Node(15);

    cout << "Root data: " << root->data << endl;
    cout << "Left child: " << root->left->data << endl;
    cout << "Right child: " << root->right->data << endl;

    return 0;
}

2️⃣ Edge

Definition: A connection between a node and its child.

Example:

If root has a left child 5, then root → left child is an edge.

In a connected tree, total edges = total nodes - 1.

3️⃣ Root

Definition: The topmost node of the tree.

The starting point of the tree.

It has no parent.

Example:

Node* root = new Node(10); // root

4️⃣ Leaf

Definition: A node that does not have any children.

Leaf nodes are the end nodes of a tree.

Example:

If 5 and 15 are child nodes and have no children → they are leaves.

5️⃣ Degree

Definition: The number of children a node has.

Example:

Node with 2 children → degree = 2

Leaf node → degree = 0

6️⃣ Height of a Node

Definition: Maximum number of edges from the node to a leaf node.

Example:

       10      <- height 2
      /  \
     5    15   <- height 1, 0
    /
   3           <- height 0

7️⃣ Depth of a Node

Definition: Number of edges from the root to the node.
       10      <- depth 0
      /  \
     5    15   <- depth 1
    /
   3           <- depth 2

1️⃣ Tree Properties

Number of Nodes

Total nodes in tree = n

Number of Edges

Edges = n - 1 (for a connected tree with n nodes)

Degree of a Node

Number of children a node has

Degree of Tree

Maximum degree of any node in the tree

Height of Tree

Maximum distance from root to a leaf

Depth of Node

Distance from root to that node

Level of Node

Depth + 1

Other properties:

A tree with n nodes has n-1 edges

There is exactly one path between any two nodes

Leaf nodes → nodes with degree 0

Internal nodes → nodes with degree ≥ 1

2️⃣ Tree Representations

Trees can be represented mainly in two ways:

A) Using Pointers (Linked Representation)

Each node stores data + pointers to children.

Easy for dynamic trees.

Commonly used in C++ with struct or class.

Example: Binary Tree in C++

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int main() {
    Node* root = new Node(10);      // root node
    root->left = new Node(5);       // left child
    root->right = new Node(15);     // right child

    cout << "Root: " << root->data << endl;
    cout << "Left Child: " << root->left->data << endl;
    cout << "Right Child: " << root->right->data << endl;
}

B) Using Adjacency List (Array of Lists / Vectors)

Tree is stored like a graph using lists.

Each index = node, each list = children.

Useful for n-ary trees.

Example: General Tree (C++ using vectors)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5; // number of nodes
    vector<int> tree[n+1]; // adjacency list, 1-indexed

    // adding edges (parent -> child)
    tree[1].push_back(2);
    tree[1].push_back(3);
    tree[2].push_back(4);
    tree[2].push_back(5);

    // print children of each node
    for(int i=1; i<=n; i++) {
        cout << "Node " << i << " children: ";
        for(int child : tree[i]) {
            cout << child << " ";
        }
        cout << endl;
    }
}


Output:

Node 1 children: 2 3
Node 2 children: 4 5
Node 3 children: 
Node 4 children: 
Node 5 children: 

✅ Definition

A binary tree is a tree data structure in which each node has at most two children: often referred to as the left child and right child. 

root nodes or sub roots must have two childrens but dont must have 2 leafes

There is exactly one root node (which has no parent).

Each node’s children themselves represent roots of their own subtrees.

It is hierarchical and recursive in nature.

📐 Structure in C++

Here’s how you can define and build a simple binary tree in C++:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int main() {
    // Create root
    Node* root = new Node(10);

    // Add children
    root->left  = new Node(5);
    root->right = new Node(15);

    // Further children
    root->left->left = new Node(3);
    root->right->right = new Node(17);

    cout << "Root: " << root->data << endl;
    cout << "Left child of root: " << root->left->data << endl;
    cout << "Right child of root: " << root->right->data << endl;
    return 0;
}

🧠 Key Points to Remember

Each node can have 0, 1, or 2 children.

The children are typically distinguished as left and right.

Subtrees follow the same definition (recursive structure).

The highest node (root) has no parent; leaves have no children.

Useful for many algorithms: traversal, searching, sorting, expressions, etc.