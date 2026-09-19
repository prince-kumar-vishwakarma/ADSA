#include <stdio.h>

int main() {
    int coins[] = {25, 10, 5, 1};
    int n = 4;
    int amount, i, count;

    printf("Enter the amount: ");
    scanf("%d", &amount);

    printf("Coins used: ");

    for (i = 0; i < n; i++) {
        count = amount / coins[i];

        if (count > 0) {
            printf("%d x %d  ", coins[i], count);
            amount = amount % coins[i];
        }
    }

    return 0;
}


// Enter the amount: 63

// Coins used: 25 x 2  10 x 1  1 x 3
