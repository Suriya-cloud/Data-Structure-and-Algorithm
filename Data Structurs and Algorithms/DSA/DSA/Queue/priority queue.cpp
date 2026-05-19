#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    int priority;
    Node(int val,int priority) {
        data = val;
        next = NULL;
        this->priority = priority;
    }
};
class Queue {
public:
    Node *front=nullptr;
    void  enqueue(int val, int priority) {
        Node *newNode = new Node(val,priority);
        if (front == nullptr || front->priority < priority) {
            newNode->next = front;
            front = newNode;
        }
        else {
            Node *temp = front;
            while (temp->next != nullptr && temp->next->priority > priority) {
                temp = temp->next;
            }
            Node* c=temp->next;
            temp->next = newNode;
            newNode->next = c;
        }
    }
   /* void  enqueue_using_data(int val) {
        Node *newNode = new Node(val);
        if (front == nullptr || front->data < val) {
            newNode->next = front;
            front = newNode;                                                                      // for arrange using only data
        }
        else {
            Node *temp = front;
            while (temp->next != nullptr && temp->next->data >val) {
                temp = temp->next;
            }
            Node* c=temp->next;
            temp->next = newNode;
            newNode->next = c;
        }
    }*/
    void display() {
        Node *temp = front;
        while (temp != nullptr) {
            cout << temp->data << " " << temp->priority << endl;
            temp = temp->next;
        }
    }
};
int main() {
    int n;
    cin >> n;
    Queue q;
    for (int i = 0; i < n; i++) {
        int a, p;
        cin >> a >> p;
        q.enqueue(a,p);
    }
    q.display();
}
