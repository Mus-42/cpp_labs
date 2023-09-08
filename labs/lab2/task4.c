#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 2 Task 4

// a(x) x^4 + 2x^2 + 1
double a(double x) {
    double x2 = x * x;
    return x2 * x2 + 2 * x2 + 1;
}

// e(x) 16x^4 + 8x^3 + 4x^2 + 2x + 1
double e(double x) {
    double x2 = x * x;
    return (16. * x2 + (8. * x + 4.)) * x2 + 2. * x + 1.;
}

int main(void) {
    double x;
    scanf("%lf", &x);

    printf("a(x) = %lf\n", a(x));
    printf("e(x) = %lf\n", e(x));
}