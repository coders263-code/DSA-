#include <iostream>
#include <vector>
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
    if(preorder[idx]==-1) return nullptr;
    Node* root=new Node(preorder[idx]);
    root->left=buildtree(preorder);
    root->right=buildtree(preorder);
    return root;


}
void preOrder(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<endl;
    preOrder(root->left);
    preOrder(root->right);
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildtree(preorder);
    preOrder(root);
    cout<<endl;
}