#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
    }
};
Node* head=nullptr;
void insertatend(int a){
    Node* newnode=new Node(a);
    if(head==nullptr){
        head=newnode;
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}
void insertatbegin(int a){
    Node* newnode=new Node(a);
    if(head==nullptr){
        head=newnode;
        return;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}
void deleteat(int k){
    Node* temp=head;
    int i=1;
    while(i<k-1){
        temp=temp->next;
        i++;
    }
    Node* a=temp->next;
    temp->next=temp->next->next;
    temp->prev=temp->prev->prev;
    delete a;
}
void insertat(int a,int k){
    Node* newnode=new Node(a);
    Node* temp=head;
    int i=1;
    if(k==1){
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return;
    }
    while(i<k-1){
        temp=temp->next;
        i++;
    }
    Node* c=temp->next;
    temp->next=newnode;
    newnode->next=c;
    newnode->prev=temp;
    c->prev=newnode;
}
void deleteatend(){
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    Node* last=temp->next;
    temp->next=nullptr;
    last->prev=nullptr;
    delete last;
}
void deleteatbegin(){
    Node* front=head;
    head=head->next;
    head->prev=nullptr;
    delete front;
}
void display(){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        insertatbegin(a);
    }
    insertat(33,3);
    deleteat(3);
    deleteatend();
    deleteatbegin();
    display();
}
