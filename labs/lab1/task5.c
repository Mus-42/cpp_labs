#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 1 Task 5

int main(void) {
    // Some input number
    const float x = 1.426f;

    // a) x^4 in 2 ops
    float a0 = x * x; // x^2
    float a1 = a0 * a0;  // x^4

    // b) x^6 in 3 ops
    float b0 = x * x; // x^2
    float b1 = b0 * b0 * b0;  // x^6

    // c) x^9 in 4 ops
    float c0 = x * x * x; // x^3
    float c1 = c0 * c0 * c0;  // x^9

    // d) x^15 in 5 ops
    float d0 = x * x; // x^2
    float d1 = d0 * d0 * x; // x^5
    float d2 = d1 * d1 * d1; // x^15

    // e) x^28 in 6 ops
    float e0 = x * x; // x^2
    float e1 = e0 * e0 * e0 * x; // x^7
    float e2 = e1 * e1; // x^14
    float e3 = e2 * e2; // x^28

    // f) x^64 in 6 ops
    float f0 = x * x; // x^2
    float f1 = f0 * f0;
    float f2 = f1 * f1; // x^8
    float f3 = f2 * f2;
    float f4 = f3 * f3;
    float f5 = f4 * f4; // x^64

    printf("x=%f\n"
           "a) x^4=%f\nb) x^6=%f\nc) x^9=%f\n"
           "d) x^15=%f\ne) x^28=%f\nf) x^64=%f\n",
           x, a1, b1, c1, d2, e3, f5
    );
}