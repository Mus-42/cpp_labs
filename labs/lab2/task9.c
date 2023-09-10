#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Lab 2 Task 9

int main(void) {
    // angles
    double a, b, c;
    // radius
    double r;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &r);

    double area = r * r * (1. / tan(a / 2.) + 1. / tan(b / 2.) + 1. / tan(c / 2.));

    printf("area = %lf\n", area);
}