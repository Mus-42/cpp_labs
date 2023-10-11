#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 7 Task 10.c

int prod_max(unsigned n, int* nums) {
    int prod = nums[0], max = prod;
    for (unsigned i = 1; i < n; i++) {
        prod *= nums[i];
        if (prod > max) {
            max = prod;
        }
    }
    return max;
}

#define N_MAX 1024

int main(void) {
    unsigned n;
    scanf("%u", &n);
    int nums[N_MAX];
    for (unsigned i = 0; i < n; i++) {
        scanf("%d", nums+i);
    }
    printf("prod_max: %d\n", prod_max(n, nums));
}