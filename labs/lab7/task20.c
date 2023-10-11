#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Lab 7 Task 20

int main(void) {
    int n;
    // n digit gray code
    scanf("%d", &n);

    // obvious that g[i]^g[i+1] = max "power of 2" factor of (i+1)
    // and g[0] is 0. so we can construct all sequence iteratively from 0 to n

    int code = 0; // accumulator (init with) g[0]
    printf("code in base10: 0");
    for (int i = 1; i < 1<<n; i++) {
        // construct g[i] from g[i-1] 
        code ^= ((i^(i-1)) >> 1) + 1; // xor with max "power of 2" factor i
        printf(", %d", code);
    }
}