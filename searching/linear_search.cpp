//adj element ko last pr ly kr jana hy 
#include <iostream>
using namespace std;
void linearsearch(int number,int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]==number){
            cout<<"Your number founded at index "<<i;
            return;
        }
            
    }cout<<"your number is not in array"<<endl;
}
int main(){
    int number=10;
    int n=5;
    int arr[]={5,6,2,1,9};
    linearsearch(number,arr,n);
    
    return 0;
}