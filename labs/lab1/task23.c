#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 1 Task 23

int main(void) {
    float v;
    scanf("%*[ *]%f", &v);
    printf("%f", v*v*v);
}