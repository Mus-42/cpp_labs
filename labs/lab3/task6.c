#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Lab 3 Task 6

int main(void) {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

    if (abs(a) < abs(b)) {
        double t = a;
        a = b;
        b = t;
    }
    if (abs(a) < abs(c)) {
        double t = a;
        a = c;
        c = t;
    }
    if (abs(c) > abs(b)) {
        double t = c;
        c = b;
        b = t;
    }

    printf("max: %lf min: %lf\n", a, c);
}   