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
};
static int idx=-1;
Node* buildtree(vector<int>preorder){
    idx++;
    if(preorder[idx]<=-1){
        return 0;
    }
Node* root=new Node(preorder[idx]);
root->left=buildtree(preorder);
root->right=buildtree(preorder);
return root;
}// function for sum
int sum(Node* root){
    if(root==nullptr){
        return 0;
    }

    int leftsum=sum(root->left);
    int rightsum=sum(root->right);
    return leftsum+rightsum+root->data;
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildtree(preorder);
    // cout<<root->data;
    cout<<"Sum of Nodes in tree: "<<sum(root);
    
}