#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 1 Task 22

int main(void) {
    int v;
    // hex number like 0x42
    scanf("0x%x", &v);
    v -= 1;
    printf("hex: %#x dec: %d\n", v, v);
}