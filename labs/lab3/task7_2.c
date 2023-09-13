#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Lab 3 Task 7.a alternate version (without pointers)

void solve_sq_eq(double a, double b, double c) {
    const double eps = 1e-9;
    if (fabs(a) < eps) {
        // bx + c = 0
        if (fabs(b) < eps) {
            if (fabs(c) < eps) {
                printf("any number is root\n");
            } else {
                printf("no roots\n");
            }
        } else {
            printf("single root: x = %lf\n", -c / b);
        }
    } else {
        double d = b*b - 4.*a*c;
        if (fabs(d) < eps) {
            printf("single root: x = %lf\n", -b / a * 0.5);
        } else if (d < 0.) {
            printf("no roots\n");
        } else {
            d = sqrt(d);
            printf("2 roots: x1 = %lf, x2 = %lf\n", (-b + d) / a * 0.5, (-b - d) / a * 0.5);
        }
    }
}



int main() {
    // example input: `1 -16 15`

    // a) ax^2 + bx + c = 0
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

    solve_sq_eq(a, b, c);
}