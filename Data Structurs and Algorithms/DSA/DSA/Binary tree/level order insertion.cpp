#include <iostream>
#include <queue>
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
void insert(int a) {
    TreeNode*newnode=new TreeNode(a);
    if (root == nullptr) {
        root = newnode;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp->left==nullptr) {
            temp->left = newnode;
            return;
        }
        else {
            q.push(temp->left);
        }
        if (temp->right==nullptr) {
            temp->right = newnode;
            return;
        }
        else {
            q.push(temp->right);
        }
    }
}
void inorders(TreeNode* root) {
    if (root==nullptr) {
        return;
    }
    inorders(root->left);
    cout << root->data << " ";
    inorders(root->right);
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        insert(a);
    }
    inorders(root);
}