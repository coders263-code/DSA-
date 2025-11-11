#include<iostream>
using namespace std;
class Node{
public:
      int data;
      Node* next;
      Node* prev;

      Node(int value){
        data=value;
        next=nullptr;
        prev=nullptr;
      }

};
class doubly{
private:
    Node* head;
    Node* tail;
public:
    doubly(){
        head=nullptr;
        tail=nullptr;
    }
    void push_at_front(int value){
        Node* newNode=new Node(value);
        if(head==nullptr){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }
    void push_at_back(int value){
        Node* newNode=new Node(value);
            if(head==nullptr){
                head=tail=newNode;
            }else{
                newNode->prev=tail;
                tail->next=newNode;
                tail=newNode;
            }
    
    }void pop_at_front(){
        
        if(head==nullptr){
            return;

        }

        Node* temp=head;
        head=head->next;

        if(head!=nullptr){
            head->prev=nullptr;
        }

        temp->next=nullptr;
        delete temp;
    }
    void printvalues(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"<=>";
            temp=temp->next;

        }
        cout<<"Null"<<endl;
        
    }
};
int main(){
    doubly dl;
    dl.push_at_front(6);
    dl.push_at_front(9);
    dl.push_at_back(9);
    dl.pop_at_front();
    dl.printvalues();
    return 0;

}