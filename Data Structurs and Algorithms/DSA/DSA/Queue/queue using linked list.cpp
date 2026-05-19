#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node (int val){
        data=val;
        next=nullptr;
    }
};
Node* front =nullptr;
Node* rear=nullptr;
void enqueue(int val){
    Node* newnode=new Node(val);
    if(front==nullptr){
        front=rear=newnode;
        return ;
    }
    Node* temp=front;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
}
void dequeue(){
    Node* c=front;
    front=front->next;
    delete c;
}
void peek(){
    cout<<front->data;
}
void display(){
    Node* temp=front;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}
void empty(){
    cout<<(front==nullptr)<<endl;
}


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        enqueue(a);
    }
    dequeue();
    display();
}