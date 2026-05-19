#include <iostream>
using namespace std;
class Queue{
public:
    int size;
    int *arr;
    int front,rear;
    Queue(int s){
        size=s;
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    void enqueue(int a){
        if(rear==size-1){
            cout<<"Queue is full";
        }
        else{
            if(front ==-1){
                front=0;
            }
            arr[++rear]=a;
        }
    }
    void dequeue(){
        if(front>rear){
            cout<<"Queue is empty";
        }
        else{
            front++;
        }
    }
    void peek(){
        if(front>rear){
            cout<<"Queue is empty";
        }
        else{
            cout<<arr[front]<<endl;
        }
    }
    void empty(){
        cout<<(rear==-1)<<endl;
    }
    void display(){
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main()
{
    int n;
    cin>>n;
    Queue q(100);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        q.enqueue(a);
    }
    q.peek();
    q.dequeue();
    q.empty();
    q.display();
}