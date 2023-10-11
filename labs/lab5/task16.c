#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Lab 5 Task 16.l

// sqrt(1 + x) = 1 + 1/2 x - 1/(2 * 4) x^2 + 1*3/(2*4*6) x^3 - ...
// |x| < 1

double sqrt_x_plus_1(double x, double eps) {
    double s = 1., mul = 0.5 * x;
    unsigned i = 1;
    do {
        s += mul;
        mul *= -x / ((i + 1.) * 2.) * (i * 2. - 1);
        i++;
    } while(fabs(mul) > eps);
    return s;
}

int main(void) {
    double x;
    scanf("%lf", &x);
    printf("sqrt_x_plus_1(%lf) = %20.16lf\n", x, sqrt_x_plus_1(x, 1e-16));
    printf("sqrt(%lf + 1.)     = %20.16lf\n", x, sqrt(x+1.));
}