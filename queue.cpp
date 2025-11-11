#include <iostream>
using namespace std;
class queue{
    int arr[5],count=0,length=5;

public:
    bool push(int value){
        if(count<length){
            arr[count++]=value;
            return true;
        }else{
            return false;
        }
    }
    bool dell(){
        if(count==0){
            return false;
        }else{
            for(int i=1;i<count;i++){
                arr[i-1]=arr[i];
            }count--;
            return true;

        }
        
    }
    void size(){
        cout<<"size of your queue: "<<count<<endl;
    }
    void front(){
        if(count==0){
            cout<<"Nothing at top!";

        }else{
            cout<<"First element in your array is :"<<arr[0]<<endl;
        }
    }
    void display(){
        if(count==0){
            cout<<"List is empty !"<<endl;
        }else{
            cout<<"Your elements in an Queue !"<<endl;
            for(int i=0;i<count;i++){
                cout<<arr[i]<<" ";
            }
        }
    }
};
int main(){
    queue q;
    q.push(56);
    q.push(45);
    q.push(45);
    q.push(45);
    q.push(43);
    q.push(45);
    // q.dell();
    // q.dell();
    q.front();
    q.size();
    q.display();
}