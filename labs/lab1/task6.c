#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 1 Task 6

int main(void) {
    float deg_c;
    printf("enter degrees in celsius:\n");
    scanf("%f", &deg_c);
    float deg_k = deg_c * 9.f / 5.f + 32.f;
    printf("degrees in f: %g", deg_k);   
}