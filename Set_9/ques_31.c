#include <stdio.h>
#include <string.h>

#define d 256

void rabinKarp(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int p = 0, t = 0, h = 1;

    // h = d^(m-1) % 101
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % 101;

    // Calculate initial hash values
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % 101;
        t = (d * t + text[i]) % 101;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j;
            for (j = 0; j < m; j++)
                if (text[i + j] != pattern[j])
                    break;

            if (j == m)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate next hash
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % 101;
            if (t < 0)
                t += 101;
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    rabinKarp(text, pattern);

    return 0;
}

// Pattern found at index 10
