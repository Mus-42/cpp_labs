#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 5 Task 8

double exp_x(double x, double eps) {
    double sum = 0., fact = 1., summon = 1., x_pow = 1.;
    unsigned i = 1;
    do {
        sum += summon;
        fact *= i;
        x_pow *= x;
        i += 1;
        summon = x_pow / fact;
    } while(summon > eps);
    return sum;
}

double fi_x(double x, double eps) {
    double sum = 0., fact = 1., summon = x, x_pow = x;
    unsigned i = 1;
    do {
        sum += summon;
        fact *= -1.;
        x_pow *= x * x;
        summon = x_pow / i / fact;
        fact *= (i+1)*(i+2);
        i += 2;
    } while(summon > eps);
    return sum;
}


int main(void) {
    double eps, x;
    scanf("%lf%lf", &eps, &x);

    // a)
    printf("exp(x) = %lf\n", exp_x(x, eps));
    // b)
    printf("fi(x) = %lf\n", fi_x(x, eps));
}