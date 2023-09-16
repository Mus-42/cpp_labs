#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 4 Task 18

int main(void) {
    // f)
    // k >= 0: x_k = (-1)^k * x^2k / 2k!

    unsigned k;
    double x;
    scanf("%u%lf", &k, &x);
    
    const double x2 = x*x;
    double x_k = 1.; // x_0

    for (int i = 1; i <= k; i++) {
        // x_i
        x_k *= -1. * x2 / (i*2*(i*2 + 1));
    }

    printf("x_%u = %lf\n", k, x_k);
}