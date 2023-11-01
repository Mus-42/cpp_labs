#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 1 Task 20

int main(void) {
    float a, b, c;
    // Input format template: "A=xxx.xxx, B=xxExxx C=xxx.xxxx"
    scanf("A=%f, B=%E C=%f", &a, &b, &c);

    float average = (a + b + c) / 3.f;
    float average_harmonic = 3.f / (1.f / a + 1.f / b + 1.f / c);

    printf("average = %.4f harmonic = %.4f\n", average, average_harmonic);
    printf("average = %.4e harmonic = %.4e\n", average, average_harmonic);
}