#include <stdio.h>

void insertionSort(int bucket[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

void bucketSort(int a[], int n)
{
    int bucket[10][100];
    int count[10] = {0};

    // Find the maximum element
    int max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    // Put elements into buckets
    for (int i = 0; i < n; i++)
    {
        int index = (a[i] * 10) / (max + 1);

        if (index >= 10)
        {
            index = 9;
        }

        bucket[index][count[index]] = a[i];
        count[index]++;
    }

    // Sort each bucket
    for (int i = 0; i < 10; i++)
    {
        insertionSort(bucket[i], count[i]);
    }

    // Combine buckets
    int k = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            a[k] = bucket[i][j];
            k++;
        }
    }
}

int main()
{
    int a[100];
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter integer elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    bucketSort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}