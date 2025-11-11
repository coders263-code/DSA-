#include <iostream>
#include <algorithm>
using namespace std;
int BinarySearch(int target,int arr[],int n){
    int st=0;
    int end=n-1;
    while(st<=end){
        int mid=(st+end)/2;
        if(target>arr[mid]){//2nd half
            st=mid+1;
        }else if(target<arr[mid]){//1st half
            end=mid-1;
        }else{
            return mid;
        }

    }return -1;
}
// void printarray(int arr[],int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i];
//     }cout<<endl;
// }
int main(){
    int target=9;
    int n=6;
    int arr[]={5,6,2,1,9,8};
        sort(arr, arr + n); // ✅ Sort array before binary search

    cout << "Sorted array: ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout<<"found at index"<<BinarySearch(target,arr,n);
    // printarray(arr,n);
    return 0;
}