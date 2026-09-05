#include<stdio.h>

// Merge sort
void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];

    for (int i = 0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for (int j = 0; j<n2; j++){
        R[j] = arr[m+1+j];
    }

    int i = 0, j = 0, k = l;

    while (i<n1 && j<n2){
        if (L[i]<=R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i<n1)
        arr[k++] = L[i++];

    while (j<n2)
        arr[k++] = R[j++];

}

void merge_sort(int arr[], int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// Print array
void print_arr(int arr[], int n){
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// Main
int main(){
    int arr[] = {2,4,1,4,6,8,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr, 0, n-1);
    print_arr(arr, n);

    return 0;
}