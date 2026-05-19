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
Node *head =nullptr;
void insertbegining(int a){
    Node *newNode=new Node(a);
    if(head==nullptr){
        head=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
}
void insertatend(int a){
    Node* newNode =new Node(a);
    if(head==nullptr){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;

}
void deleteend(){
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    Node* b=temp->next;
    temp->next=nullptr;
    delete b;
}

void instertatmid(int a,int k){
    Node* newNode=new Node(a);
    int i=1;
    Node* temp=head;
    while(temp->next!=nullptr && i< k-1){
        temp=temp->next;
        i++;
    }
    Node* c=temp->next;
    temp->next=newNode;
    newNode->next=c;
}
void display(){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        insertbegining(a);
    }
    instertatmid(35,4);
    display();
    return 0;

}