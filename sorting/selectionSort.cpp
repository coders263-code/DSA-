//smallest index ko next sy compare krty hy
#include<iostream>
using namespace std;
void SelectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int si=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[si]){
                si=j;
            }
            swap(arr[i],arr[si]);
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
    int arr[]={5,3,8,1,0};
    SelectionSort(arr,n);
    printarray(arr,n);
}