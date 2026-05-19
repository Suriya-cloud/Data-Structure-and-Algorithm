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

// TreeNode* insert(TreeNode* root, int a) {
//     TreeNode* newNode=new TreeNode(a);
//     if(root==nullptr) {
//         root=newNode;
//         return root;
//     }
//     else if (a<root->data) {
//         root->left=insert(root->left,a);
//     }
//     else if (a>=root->data) {
//         root->right=insert(root->right,a);
//     }
//     return root;
// }

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


void inorders(TreeNode* root) {
    if (root==nullptr) {
        return;
    }
    inorders(root->left);
    cout << root->data << " ";
    inorders(root->right);
}
void preorders(TreeNode* root) {
    if (root==nullptr) {
        return;
    }
    cout << root->data << " ";
    preorders(root->left);
    preorders(root->right);
}
void postorders(TreeNode* root) {
    if (root==nullptr) {
        return;
    }
    postorders(root->left);
    postorders(root->right);
    cout << root->data << " ";
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        insert(root,a);            //root=insert(root,a);
    }
    inorders(root);
}