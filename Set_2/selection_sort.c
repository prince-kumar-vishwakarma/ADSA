#include<stdio.h>

// Selection sort
void selection_sort(int arr[], int n){
    for (int i = 0; i<n-1; i++){
        int min = i;
        for (int j = i+1; j<n; j++){
            if (arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
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
    selection_sort(arr, n);
    print_arr(arr, n);

    return 0;
}