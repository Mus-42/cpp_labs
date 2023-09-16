#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Lab 2 Task 17

double bent(double x) {
    return sqrt(x * x + 1.) * 0.5 - 0.5 + x;
}

double bent_derivative(double x) {
    return  x / sqrt(x * x + 1.) * 0.5 + 1.;
}

int main(void) {
    double x;
    scanf("%lf", &x);
    printf("bent(%lf) = %lf\n", x, bent(x));
    printf("bent_derivative(%lf) = %lf\n", x, bent_derivative(x));
}