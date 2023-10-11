#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Lab 5 Task 19

double f(double x) {
    return tan(x) - x;
}

int main(void) {
    // ex: tg x = x
    // range: x in [0.001; 1.5]
    double l = 0.001, r = 1.5;
    double e = 1e-9; // precision

    // in this range: tg(x) < tg(y)  <=> x < y

    while (r - l > e) {
        double m = (l + r) * 0.5;
        if (f(m) > 0.) {
            r = m;
        } else {
            l = m;
        }
    }

    double x = (l + r) * 0.5;
    printf("x = %lf\n", x);
    // solution obvious: tg(0) = 0. so answer is always `l`
}