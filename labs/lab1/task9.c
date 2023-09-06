#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 1 Task 9

int main(void) {
    float a, b;
    scanf("%f %f", &a, &b);
    float av = (a+b)/2.;
    float h = 2./(1./a+1./b);

    printf("av = %f\nh = %f\n", av, h);

    printf("\nav = %e\nh = %e\n", av, h);
}