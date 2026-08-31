#include<stdio.h>
// Insertion sort
void insertion_sort(int arr[], int n){
    for (int i = 1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
    insertion_sort(arr, n);
    print_arr(arr, n);

    return 0;
}