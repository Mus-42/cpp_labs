#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Lab 1 Task 2

int main(void) {
    double a = 1e-4;
    double b = 24.33e5;
    double c = M_PI;
    double d = M_E;
    double e = sqrt(5.);
    double f = log(100.);

    printf("%.2lf ", a);
    printf("%.2lf ", b);
    printf("%.2lf ", c);
    printf("%.2lf ", d);
    printf("%.2lf ", e);
    printf("%.2lf ", f);
}