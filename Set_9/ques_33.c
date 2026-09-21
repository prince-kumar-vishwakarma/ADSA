#include <stdio.h>
#include <string.h>

#define SIZE 256

void boyerMoore(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int bad[SIZE];

    // Initialize bad character table
    for (int i = 0; i < SIZE; i++)
        bad[i] = -1;

    // Store last occurrence of each character
    for (int i = 0; i < m; i++)
        bad[(unsigned char)pattern[i]] = i;

    int s = 0;  // Shift of pattern

    while (s <= n - m) {
        int j = m - 1;

        // Compare from right to left
        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            printf("Pattern found at index %d\n", s);

            // Shift pattern
            if (s + m < n)
                s += m - bad[(unsigned char)text[s + m]];
            else
                s++;
        } else {
            int shift = j - bad[(unsigned char)text[s + j]];
            s += (shift > 1) ? shift : 1;
        }
    }
}

int main() {
    char text[] = "ABAAABCD";
    char pattern[] = "ABC";

    boyerMoore(text, pattern);

    return 0;
}


// Pattern found at index 4
// 