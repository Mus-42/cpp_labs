#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Lab 4 Task 4

// x + 2x^2 + nx^n  =  0 <= i <= n  sum(i * x^i)
double calc_poly(int n, double x) {
    //  x + 2x^2 + nx^n  =  1 <= i <= n  sum(i * x^i)
    // = x * (x + x^2 + ... + x^n)'
    double x_pow = 1., sum = 0.;
    for (int i = 1; i <= n; i++) {
        x_pow *= x;
        sum += i * x_pow;
    }
    return sum;
}

int main(void) {
    int n;
    double x;
    scanf("%d%lf", &n, &x);

    printf("P(%d, %lf) = %lf\n", n, x, calc_poly(n, x));
}