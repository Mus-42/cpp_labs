#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Lab 2 Task 3

int main(void) {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double p = (a+b+c)/2.;
    double s = sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%lf\n", s);
}