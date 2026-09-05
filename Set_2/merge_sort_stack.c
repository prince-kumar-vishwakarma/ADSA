#include <stdio.h>

typedef struct
{
    int left;
    int right;
    int state;
} StackNode;

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
    StackNode stack[100];
    int top = -1;

    // Push initial problem
    top++;
    stack[top].left = 0;
    stack[top].right = n - 1;
    stack[top].state = 0;

    while (top >= 0)
    {
        int left = stack[top].left;
        int right = stack[top].right;
        int state = stack[top].state;

        // Remove current node from stack
        top--;

        // If only one element, nothing to sort
        if (left >= right)
        {
            continue;
        }

        int mid = (left + right) / 2;

        if (state == 0)
        {
            /*
             * Simulate:
             * mergeSort(left, right)
             *
             * First solve left half, then right half,
             * then merge them.
             */

            // Push merge operation
            top++;
            stack[top].left = left;
            stack[top].right = right;
            stack[top].state = 1;

            // Push right half
            top++;
            stack[top].left = mid + 1;
            stack[top].right = right;
            stack[top].state = 0;

            // Push left half
            top++;
            stack[top].left = left;
            stack[top].right = mid;
            stack[top].state = 0;
        }
        else
        {
            // Both halves are sorted, so merge them
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
