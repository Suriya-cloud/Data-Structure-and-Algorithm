#include<iostream>
using namespace std;
int main() {
    int n,e;
    cin>>n>>e;
    int adjmatrix[n][n]={0};
    for(int i=0;i<e;i++) {
        int u,v;
        cin>>u>>v;
        adjmatrix[u][v]=1;
        adjmatrix[v][u]=1;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
             cout<<adjmatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}