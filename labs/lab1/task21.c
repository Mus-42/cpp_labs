#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 1 Task 21

int main(void) {
    float a;
    scanf("%f", &a);

    printf(
        "- | - | %.2f | - | -\n"
        "- | %.2f | %.2f | %.2f | -\n"
        "%.2f | %.2f | %.2f | %.2f | %.2f\n",
        a, a, a, a, a, a, a, a, a
    );
}