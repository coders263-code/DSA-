#include <iostream>
using namespace std;
class Stack{
    int arr[5];
    int count=0;
    int length=5;
public:
    bool push(int value){
        if(count<length){
            arr[count++]=value;
            return true;
        }else{
            return false;
        }
    }

    bool pop(){
        if(count>0){
            return count--;
        }else{
            return false;
        }
    }
    void top(){
        if(count==0){
            cout<<"List is empty !";
        }else{
            cout<<"Top element in your stack is :\n"<<arr[count-1]<<endl;
        }
    }
    void size(){
        cout<<"size of your stack is !"<<" "<<count<<endl;
    }
    void display(){
        if(count==0){
            cout<<"List is empty!";
        }else{
            cout<<"your list elements are :"<<endl;
            for(int i=0;i<count;i++){
                cout<<arr[i]<<" ";
            }
        }
    }
};
int main(){

    Stack st;
    st.push(56);
    st.push(45);
    st.push(45);
    st.push(45);
    st.push(45);
    st.pop();
    st.pop();
    st.top();
    st.size();
    st.display();   
}