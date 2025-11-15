#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data=value;
        left=right=nullptr;
    }
};static int idx=-1;
Node* buildtree(vector<int>preorder){
    idx++;
    if(preorder[idx]<=-1){
        return nullptr;
    }
    Node* root= new Node(preorder[idx]);
    root->left=buildtree(preorder);
    root->right=buildtree(preorder);
    return root;
}


//Code for height Of tree
int height(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    return max(leftheight,rightheight)+1;
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildtree(preorder);
    cout<<"height of tree:"<<height(root);

}