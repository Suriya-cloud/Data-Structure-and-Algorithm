#include <iostream>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) {
        this->data = data;
        left=nullptr;
        right=nullptr;
    }
};
TreeNode* root=nullptr;
void insert(TreeNode* &root, int a) {
    TreeNode* newNode=new TreeNode(a);
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
void search(TreeNode* &root, int a) {
    if(root==nullptr) {
        cout<<"Not found";
        return;
    }
    if (root->data==a) {
        cout<<"Found";
        return;
    }
    else if (a<root->data) {
        search(root->left,a);
    }
    else if (a>=root->data) {
        search(root->right,a);
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
    search(root,1);
}