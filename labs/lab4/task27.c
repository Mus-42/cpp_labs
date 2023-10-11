#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Lab 4 Task 27

// calculate GCD & coefficients
// 0 < a <= b
int gcd(int a, int b, int* av, int* bv) {
    int c = b % a;
    if (c == 0) {
        *bv = 0;
        *av = 1;
        return a;
    } else {
        int d = b / a;
        // c = b - a * d

        // gcd(a, b) = gcd(a, c) = a * av + c * bv
        // = a * av + (b - a * d) * bv
        // = a * (av - d * bv) + b * bv

        int ret = gcd(c, a, bv, av);
        *av -= d * *bv;
        return ret;
    }
}

int main(void) {
    int a, b, c;
    // Diophantine equation ax + by = c
    // a, b, c > 0 by problem statement
    scanf("%d%d%d", &a, &b, &c);

    int av = 0, bv = 0, v = 0;

    // calc gcd & coefficients 
    if (a < b) {
        v = gcd(a, b, &av, &bv);
    } else {
        v = gcd(b, a, &bv, &av);
    }

    if (c % v != 0) {
        printf("no solutions");
    } else {
        int m = c / v;
        printf("x = %d y = %d\n", av * m, bv * m);
        printf("%d * %d + %d * %d = %d\n", a, av * m, b, bv * m, c);
    }
}