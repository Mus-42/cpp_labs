#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Lab 1 Task 13

int main(void) {
    double x;
    scanf("%lf", &x);
    printf("lg(x) = %.3lf", log10(x));
}