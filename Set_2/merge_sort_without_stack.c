#include <stdio.h>

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

void mergeSort(int a[], int n)
{
    // size = size of already sorted subarrays
    for (int size = 1; size < n; size = size * 2)
    {
        // Merge adjacent subarrays
        for (int left = 0; left < n - 1; left = left + 2 * size)
        {
            int mid = left + size - 1;
            int right = left + 2 * size - 1;

            // If right part is outside array
            if (mid >= n)
                break;

            if (right >= n)
                right = n - 1;

            merge(a, left, mid, right);
        }
    }
}

int main()
{
    int a[100];
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    mergeSort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}