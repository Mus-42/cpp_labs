#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Lab 5 Task 20

// y(x) = x^3 + 4x^2 + x - 6
double y(double x) {
    double x2 = x*x;
    return x2 * (x + 4.) + x - 6.;
}

int main(void) {
    // x^3 + 4x^2 + x - 6
    double a = 0., b = 2.;
    const double eps = 1e-9;

    const double x0 = 0.5 * (a+b);
    const double yb = y(b);
    double x = x0;

    while (1) {
        // chord method
        double next_x = x - y(x) * (x - b) / (y(x) - yb);
        if (fabs(next_x-x) < eps) {
            x = next_x;
            break;
        }
        x = next_x;
    }
    
    // for this particular function answer is 1.
    // but this code works for other similar functions
    printf("x = %lf\n", x);
}