#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Lab 5 Task 22

double calc_pi(double a, double b, double t) {
    double ab = a + b;
    return ab * ab / t * 0.25;
}

int main(void) {
    double a = 1.;
    double b = M_SQRT1_2;
    double t = 0.25;
    double p = 1.;

    double pi = calc_pi(a, b, t);

    const double eps = 1e-9;

    while (1) {
        double new_a = (a + b) * 0.5;
        double new_b = sqrt(a * b);
        double new_t = t - p * (a - new_a) * (a - new_a);
        double new_p = 2. * p;

        double new_pi = calc_pi(new_a, new_b, new_t);
        if (fabs(pi - new_pi) < eps) {
            pi = new_pi;
            break;
        }
        pi = new_pi;

        a = new_a;
        b = new_b;
        t = new_t;
        p = new_p;
    }

    printf("pi = %.9lf\n", pi);
}