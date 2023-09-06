#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 1 Task 24

int main(void) {
    int n, m;
    scanf("%i%i", &n, &m);
    printf("%*i\n%*i\n", n, m, 2*n, m*m);
}