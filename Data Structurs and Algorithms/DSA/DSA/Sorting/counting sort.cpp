void counting_sort(int *arr,int a) {
    int max=0;
    for (int i = 0; i < a; i++) {
        if (max<arr[i]) {
            max=arr[i];
        }
    }
    int freq[max+1]={0};
    for (int i=0;i<a;i++) {
        freq[arr[i]]++;
    }
    int ind=0;
    for (int i=0;i<=max;i++) {
        while (freq[i]>0) {
            arr[ind++]=i;
            freq[i]--;
        }
    }

}

4 2 2 8 3 3 1