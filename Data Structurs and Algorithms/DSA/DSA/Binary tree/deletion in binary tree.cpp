Node* minimum(Node* root) {
    Node* temp=root;
    while(temp->left!=nullptr) {
        temp=temp->left;
    }
    return temp;
}
void deleteNode(Node* root,int a) {
    if(root==nullptr) {
        return;
    }
    else if (a<root->data) {
        deleteNode(root->left,a);
    }
    else if (a>root->data) {
        deleteNode(root->right,a);
    }
    else {
        // No child
        if(root->left==nullptr && root->right==nullptr) {
            delete root;
        }
        // One child
        if (root->right==nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
            return;
        }
        if (root->left==nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
            return;
        }
        //Two child
        Node* temp=minimum(root->right);
        root->data=temp->data;
        deleteNode(root->right,temp->data);
    }
}