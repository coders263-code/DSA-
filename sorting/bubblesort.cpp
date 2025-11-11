//adj element ko last pr ly kr jana hy 
#include <iostream>
using namespace std;
void sorting(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>=arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }cout<<endl;
}
int main(){
    int n=5;
    int arr[]={5,6,2,1,9};
    sorting(arr,n);
    printarray(arr,n);
    return 0;
}
