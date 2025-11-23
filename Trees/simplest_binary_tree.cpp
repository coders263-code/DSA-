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
Node* buildtree(int arr[],int n){
    idx++;
        if (idx >= n || arr[idx] == -1)
        return nullptr;
    Node* root=new Node(arr[idx]);
    root->left=buildtree(arr,n);
    root->right=buildtree(arr,n);
    return root;


}
int main(){
    int n=11;
    int arr[n];
    cout<<"Enter your value:";
    for (int i = 0; i < 7; i++)
    {
        cin>>arr[i];
    }
    
    Node* root=buildtree(arr,n);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<"Right Node root:"<<root->right->data<<endl;

}