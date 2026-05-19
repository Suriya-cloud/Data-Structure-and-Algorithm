#include<iostream>
#include<vector>
#include<queue>

using namespace std;
void bsf(vector<vector<int>> adjList,int start,int n) {
    queue<int> q;
    q.push(start);
    int visited[n]={0};
    visited[start]=1;
    while(!q.empty()) {
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for (int k:adjList[temp]) {
            if(visited[k]==0) {
                q.push(k);
                visited[k]=1;
            }
        }
    }
}
int main() {
    int n,e;
    cin>>n>>e;
    vector<vector<int>> adjList(n);
    for(int i=0;i<e;i++) {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int i=0;i<n;i++) {
        cout<<i<<" ";
        for (int k:adjList[i]) {
            cout<<k<<" ";
        }
    }
    bsf(adjList,0,n);
    cout<<endl;
}