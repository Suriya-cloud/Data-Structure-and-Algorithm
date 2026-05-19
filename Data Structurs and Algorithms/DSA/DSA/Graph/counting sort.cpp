#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void counting_sort(int *arr, int n){
	int max=0;
	for(int i=0; i<n; i++){
		if(max<arr[i]){
			max=arr[i];
		}
	}
	int freq[max+1]={0};
	for(int i=0; i<n; i++){
		freq[arr[i]]++;
	}
	int ind = 0;
	for (int i=0; i<=max; i++){
		while(freq[i]>0){
			arr[ind++]=i;
			freq[i]--;
		}
	}
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}

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
	//int n, e;
	//cin>>n>>e;
	//vector<vector<int>> adjList(n);
	//vector<bool> visited(n);
	//for(int i=0; i<e; i++){
	//	int u, v;
	//	cin>>u>>v;
	//
	//	adjList[u].push_back(v);
	//	adjList[v].push_back(u);
	//}
	//
	//dsf(adjList, visited, 0, n);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	counting_sort(arr, n);

}