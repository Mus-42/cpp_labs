#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 2 Task 4

// a(x) x^4 + 2x^2 + 1
double a(double x) {
    double x2 = x * x;
    return x2 * x2 + 2 * x2 + 1;
}

// b(x) x^4 + x^3 + x^2 + x + 1
// 2 multiplications, 3 additions (less than in geometric series version)
double b(double x) {
    double x2 = x * x; // x^2
    x += 1.; // x+1
    return (x2 + x) * x2 + x; // (x^2 + x+1) * x^2 + x+1 = b(x)
}

// e(x) 16x^4 + 8x^3 + 4x^2 + 2x + 1
// 3 multiplications, 3 additions
double e(double x) {
    x *= 2.; // 2x
    double x2 = x * x; // 4x^2
    x += 1.; // 2x+1
    return (x2 + x) * x2 + x; // (4x^2 + 2x+1) * 4x^2 + 2x+1 = e(x)
}

// e(x) 16x^4 + 8x^3 + 4x^2 + 2x + 1
// 3 multiplications, 2 subtractions, 1 division
double e_geometric(double x) {
    // 16x^4 + 8x^3 + 4x^2 + 2x + 1 = sum  0 <= i <= 4  (2x)^i = ((2x)^5 - 1)/((2x) - 1)
    x *= 2.;
    double x2 = x * x;
    return (x2 * x2 * x - 1.) / (x - 1.);
}

int main(void) {
    double x;
    scanf("%lf", &x);

    // class variant
    printf("a(x) = %lf\n", a(x));

    // variant `б` (assigned to me) 
    printf("b(x) = %lf\n", b(x));

    // variant `д`
    printf("e(x) = %lf\n", e(x));
    printf("e_geometric(x) = %lf\n", e_geometric(x));
}