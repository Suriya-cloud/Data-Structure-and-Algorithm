#include <iostream>
using namespace std;
class MinHeap {
    public:
        int size;
        int *arr;
        int ind;
    MinHeap(int size) {
        this->size = size;
        arr = new int[size];
        ind = 0;
    }
    int getparent(int ind) {
        return ((ind-1)/2);
    }
    void insert(int a) {
        if (ind==size) {
            cout<<"Max heap overflow"<<endl;
            return;
        }
        arr[ind]=a;
        int k=ind;
        ind++;
        while (k>0 && arr[getparent(k)]>arr[k]) {
            int parent=getparent(k);
            int temp=arr[parent];
            arr[parent]=arr[k];
            arr[k]=temp;
            k=parent;
        }
    }
    void display() {
        for (int i=0;i<ind;i++) {
            cout<<arr[i]<<" ";
        }
    }
};
int main() {
    int n;
    cin>>n;
    MinHeap heap(n);
    for (int i=0;i<n;i++) {
        int a;
        cin>>a;
        heap.insert(a);
    }
    heap.display();
}