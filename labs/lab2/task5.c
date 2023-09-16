#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 2 Task 5

double rosenbrock2d(double x, double y) {
    double t1 = x * x - y;
    double t2 = x - 1.;
    return 100. * t1 * t1 + t2 * t2;
}

int main(void) {
    printf("%lf\n", rosenbrock2d(0., 1.));
    printf("%lf\n", rosenbrock2d(1., 1.));
    printf("%lf\n", rosenbrock2d(1., 0.));
}