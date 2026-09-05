#include<stdio.h>


void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}
// nn
void heapSort(int a[], int n)
{
    /* Build max heap */
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    /* Extract elements */
    for (int i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
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
    heapSort(arr, n);
    print_arr(arr, n);

    return 0;
}