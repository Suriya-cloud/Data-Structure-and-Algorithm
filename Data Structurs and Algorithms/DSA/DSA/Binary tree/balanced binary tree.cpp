void height(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        h++;
        for(int i=0; i<size; i++) {
            Node* temp = q.front();
            q.pop();
            if(temp->left!=nullptr) {
                q.push(temp->left);
            }
            if(temp->right!=nullptr) {
                q.push(temp->right);
            }
        }
    }
    cout<<h<<endl;
}