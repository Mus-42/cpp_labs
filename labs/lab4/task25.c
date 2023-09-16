#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Lab 4 Task 25

// period length of rational number n/m in repeating decimal representation
unsigned period_length(unsigned n, unsigned m) {
    n %= m;

    // simplify m if it not coprime to 10
    while (m % 2 == 0 || m % 5 == 0) {
        // period length of n/m is same as 10n/m
        
        if (m % 2 == 0) {
            m /= 2;
        } else {
            n *= 2;
        }
        if (m % 5 == 0) {
            m /= 5;
        } else {
            n *= 5;
        }
        n %= m;
    }
    // now m coprime to 10

    if (n == 0) {
        // terminated fraction
        return 0;
    }

    unsigned first = n, len = 0;

    // not more than m iterations 
    do {
        len++;
        n = n * 10 % m;
    } while (n != first);

    return len;
}

int main(void) {
    // test
    if (
        period_length(1, 7)   != 6 || // 1/7   = 0.(1428571)
        period_length(1, 9)   != 1 || // 1/9   = 0.(1)
        period_length(1, 28)  != 6 || // 1/28  = 0.03(571428)
        period_length(100, 9) != 1 || // 100/9 = 11.(1)
        period_length(33, 3)  != 0 || // 33/3  = 11
        period_length(3, 25)  != 0 || // 3/25  = 0.12
        period_length(1, 89)  != 44
    ) {
        puts("test failed");
        return EXIT_FAILURE;
    }

    // n / m, m > 0
    int n;
    unsigned m;
    scanf("%d%u", &n, &m);
    
    // period length of -n/m same as for n/m
    unsigned k = n < 0 ? -n : n;

    printf("period len: %u", period_length(k, m));
}