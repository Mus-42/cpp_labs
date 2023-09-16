#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Lab 2 Task 2

int main(void) {
    double a, b;
    scanf("%lf%lf", &a, &b);
    double h = hypot(a, b);
    printf("%lf\n", h);
}