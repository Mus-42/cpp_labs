#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Lab 3 Task 23.a

double onestep(double x) {
    if (x < 0.) {
        return 0.;
    }
    return 1.;
}

double onestep_derivative(double x) {
    const double eps = 1e-18;
    if (fabs(x) > eps) {
        return 0.;
    }
    return INFINITY;
}

int main(void) {
    double x;
    scanf("%lf", &x);
    printf(
        "onestep(%lf) = %lf\nonestep_derivative(%lf) = %lf",
        x, onestep(x), x, onestep_derivative(x)
    );
}