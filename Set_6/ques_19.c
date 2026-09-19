#include <stdio.h>

#define N 4

int weight[] = {1, 3, 4, 5};
int value[]  = {1, 4, 5, 7};
int capacity = 7;

int maxValue = 0;

void knapsack(int i, int currentWeight, int currentValue) {
    if (i == N) {
        if (currentValue > maxValue)
            maxValue = currentValue;
        return;
    }

    // Include item
    if (currentWeight + weight[i] <= capacity)
        knapsack(i + 1, currentWeight + weight[i],
                 currentValue + value[i]);

    // Exclude item
    knapsack(i + 1, currentWeight, currentValue);
}

int main() {
    knapsack(0, 0, 0);

    printf("Maximum value = %d\n", maxValue);

    return 0;
}

// Maximum value = 9