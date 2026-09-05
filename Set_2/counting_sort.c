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

void countingSort(int a[], int n)
{
    if (n <= 0)
        return;

    int max = getMax(a, n);

    int count[max+1];

    for (int i = 0; i < n; i++)
        count[a[i]]++;

    int k = 0;

    for (int i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            a[k++] = i;
            count[i]--;
        }
    }

    free(count);
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

    countingSort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}