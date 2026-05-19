#include <iostream>
#include <ostream>
using namespace std;
int hashfunction(int key,int size) {
    return key%size;
}
void insert(int hashtable[],int key,int size) {
    int ind=hashfunction(key,size);
    hashtable[ind]=key;
}
void search(int hashtable[],int key,int size) {
    int ind=hashfunction(key,size);

    if(hashtable[ind]==key) {
        cout<<"Found"<<endl;
    }
    else {
        cout<<"Not Found"<<endl;
    }
}
int main() {
    int n;
    cin>>n;
    int hashtable[n];
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        insert(hashtable,a,n);
    }
    search(hashtable,35,n);
    for (int i=0;i<n;i++) {
        cout<<hashtable[i]<<" ";
    }
    return 0;
}