#include<iostream>
#include<vector>
using namespace std;
void dsf(vector<vector<int>> adjList,int start,vector<bool> &visited){
    visited[start]=true;
    cout<<start<<" ";
    for (int k:adjList[start]) {
        if (visited[k]==false) {
            dsf(adjList,k,visited);
        }
    }

}
int main() {
    int n,e;
    cin>>n>>e;
    vector<vector<int>> adjList(n);
    vector<bool> visited(n,false);
    for(int i=0;i<e;i++) {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int k;
    cin>>k;
    dsf(adjList,k,visited);
    cout<<endl;
}