#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 4 Task 28

int main(void) {
    int n;
    scanf("%d", &n);

    // We don't have any time complexity constraints, so naive O(n^4) approach will be fine?

    // example: 5 = 4**2 + 1**2
    for (int a = 1; a * a < n; a++) {
        for (int b = 1; b <= a; b++) {
            if (a * a + b * b == n) {
                printf("a = %d, b = %d\n", a, b);
                return 0;
            }
        }
    }

    // example 123 = 2 * 7**2 + 5**2
    for (int a = 1; a * a < n; a++) {
        for (int b = 1; b <= a; b++) {
            for (int c = 1; c <= b; c++) {
                if (a * a + b * b + c * c == n) {
                    printf("a = %d, b = %d, c = %d\n", a, b, c);
                    return 0;
                }
            }
        }
    }

    // example: 124 = 3 * 6**2 + 4**2
    for (int a = 1; a * a < n; a++) {
        for (int b = 1; b <= a; b++) {
            for (int c = 1; c <= b; c++) {
                for (int d = 1; d <= c; d++) {
                    if (a * a + b * b + c * c + d * d == n) {
                        printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
                        return 0;
                    }
                }
            }
        }
    }

    puts("not found");
}