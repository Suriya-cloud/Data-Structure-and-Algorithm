#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dsf(vector<vector<int>> adjList, vector<bool> &visited, int start, int n){
	visited[start]=true;
	cout<<start<<" ";
	for(int k:adjList[start]){
		if(!visited[k]){
			dsf(adjList, visited, k, n);
		}
	}
}

int main(){
	int n, e;
	cin>>n>>e;
	vector<vector<int>> adjList(n);
	vector<bool> visited(n);
	for(int i=0; i<e; i++){
		int u, v;
		cin>>u>>v;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	dsf(adjList, visited, 0, n);
}