#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 1 Task 8

int main(void) {
    float a, b;
    scanf("%f%f", &a, &b);
    printf("a-b = %.2f\na+b = %.2f\n", a-b, a*b);
}