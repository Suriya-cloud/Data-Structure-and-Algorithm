#include <iostream>
#include<queue>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        left=nullptr;
        right=nullptr;
    }
};
Node* root= nullptr;
void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=nullptr)
            q.push(temp->left);
        if(temp->right!=nullptr)
            q.push(temp->right);
    }
}
void insert(Node* &root, int a) {
    Node* newNode=new Node(a);
    if(root==nullptr) {
        root=newNode;
        return;
    }
    else if (a<root->data) {
        insert(root->left,a);
    }
    else if (a>=root->data) {
        insert(root->right,a);
    }
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        insert(root,a);
    }
    levelOrder(root);
}
