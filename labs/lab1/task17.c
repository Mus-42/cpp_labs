#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Lab 1 Task 17

int main(void) {
    long double x;
    // 0 <= x <= 1e4
    scanf("%Lf", &x);

    long double y = x * x; //x^2
    y *= y; // x^4
    y *= y; // x^8

    // [at least] 20 before `.` + 1 (`.`) + 4 after = width 25  
    printf("%025.4Lf", y);
}