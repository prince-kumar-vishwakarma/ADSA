#include <stdio.h>

int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    return max;
}

int getHighestBit(int a[], int n)
{
    int max = getMax(a, n);
    int bit = 0;

    while ((max >> bit) > 1)
        bit++;

    return bit;
}

void radixExchangeSortRec(int a[], int left, int right, int bit)
{
    if (left >= right || bit < 0)
        return;

    int i = left;
    int j = right;

    while (i <= j)
    {
        while (i <= right && ((a[i] >> bit) & 1) == 0)
            i++;

        while (j >= left && ((a[j] >> bit) & 1) == 1)
            j--;

        if (i < j)
            swap(&a[i], &a[j]);
    }

    radixExchangeSortRec(a, left, j, bit - 1);
    radixExchangeSortRec(a, i, right, bit - 1);
}

void radixExchangeSort(int a[], int n){
    if (n <= 0)
        return;

    int bit = getHighestBit(a, n);

    radixExchangeSortRec(a, 0, n - 1, bit);
}

int main()
{
    int a[100];
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter non-negative elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    radixExchangeSort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}