void merge(int *arr,int low,int mid,int high) {
    int n1=mid-low+ 1;
    int n2=high-mid;
    int larr[n1];
    int rarr[n2];
    for (int i=0;i<n1;i++) {
        larr[i]=arr[low+i];
    }
    for (int i=0;i<n2;i++) {
        rarr[i]=arr[mid+i+1];
    }
    int i=0;
    int j=0;
    int k=low;
    while (i<n1 && j<n2) {
        if(larr[i]<rarr[j]) {
            arr[k]=larr[i];
            k++;
            i++;
        }
        else {
            arr[k]=rarr[j];
            j++;
            k++;
        }
    }
    while (i<n1) {
        arr[k]=larr[i];
        i++;
        k++;
    }
    while (j<n2) {
        arr[k]=rarr[j];
        j++;
        k++;
    }
}
void merge_sort(int *arr,int low,int high) {
    if (low>=high) {
        return;
    }
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}