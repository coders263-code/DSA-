#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data=value;
        next=nullptr;
    }
};
class linkedlist{
private:
    Node* head;
    Node* tail;
public:
    linkedlist() {
        head=nullptr;
        tail=nullptr;
    }

    void push_front(int value){
        Node* newNode=new Node(value);
        if(head==nullptr){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }

  
    }
    void push_back(int value){
        Node* newNode=new Node(value);
        if(head==nullptr){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void push_at_any(int value,int pos){
        if(pos<0){
            cout<<"empty";
            return;
        }else if(pos==0){
            push_front(value);
        }else{
            Node* temp=head;
            for(int i=0;i<pos-1;i++){
                temp=temp->next;
            }
            Node* newNode=new Node(value);
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
    void pop_front(){
        if(head==nullptr){
            return;
        }else{
            Node* temp=head;
            head=head->next;
            temp->next=nullptr;
            delete temp;
        }
    }
    void pop_back(){
        if(head==nullptr){
            return;
        }else if (head == tail) {
        // only one element
        delete head;
        head = tail = nullptr;
    } else{
            Node* temp=head;
            while(temp->next!=tail){
                temp=temp->next;

            }temp->next=nullptr;
            delete tail;
            tail=temp;
        }
    }
    void printvalues(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;

        }
        cout<<"Null"<<endl;
        
    }
    int search(int key){
        Node* temp=head;
        int idx=0;
        while(temp!=nullptr){
            if(temp->data==key){
                return idx;
            }else{
                temp=temp->next;
                idx++;
            }
        }return -1;
    }
};
int main(){
    linkedlist ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(9);
    ll.push_at_any(6,3);
    ll.printvalues();
    cout<<"Founded at index "<<ll.search(9)<<endl;
    // ll.pop_front();
    // ll.pop_back();
    
}