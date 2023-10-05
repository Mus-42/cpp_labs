#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Lab 5 Task 12.c

double s_n(unsigned n) {
    if (n < 2) {
        return n * 2. / 3.;
    }
    double k2 = 2., k_fact = 1., s = 2./3.;
    double a = 1., b = 1.;
    for (unsigned i = 2; i <= n; i++) {
        k2 *= 2.;
        k_fact *= i;
        double new_a = 2. * a + 3. * b;
        double new_b = 2. * a + b;
        a = new_a;
        b = new_b;
        s += k2 / k_fact / (a + b + 1.);
    }
    return s;
}

int main(void) {
    unsigned n;
    scanf("%u", &n);
    printf("%lf\n", s_n(n));
}

