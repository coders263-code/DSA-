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
    if(preorder[idx]==-1){
        return 0;
    }
    Node* root=new Node(preorder[idx]);
    root->left=buildtree(preorder);
    root->right=buildtree(preorder);
    return root;
}
//This code/Followed for counting Number of Nodes in given code
int count_of_nodes(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftcount=count_of_nodes(root->left);
    int rightcount=count_of_nodes(root->right);
    return leftcount+rightcount+1;
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildtree(preorder);
    cout<<"No of nodes in your tree structure:"<<count_of_nodes(root);

}