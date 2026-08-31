#include<stdio.h>

// Bubble sort
void bubble_sort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
    bubble_sort(arr, n);
    print_arr(arr, n);

    return 0;
}