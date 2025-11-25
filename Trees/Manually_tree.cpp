#include<iostream>
using namespace std;
class Node{
public:
      int data;
      Node* right;
      Node* left;
    Node(int value){
        data=value;
        left=right=nullptr;
    }
};
int main(){
    Node* root=new Node(10);
    root->left=new Node(2);
    root->right=new Node(7);
    root->left->right=new Node(3);
    root->right->left=new Node(5);
    root->right->right=new Node(10);

cout << "Root: " << root->data << endl; 
cout << "Left child of root: " << root->left->data << endl;  
cout << "Right child of root: " << root->right->data << endl;
return 0;
}