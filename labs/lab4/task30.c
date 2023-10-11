#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 4 Task 30

// 0 < a <= b
int gcd(int a, int b) {
    if (b%a == 0) {
        return a;
    }
    return gcd(b%a, a);
}

int euler(int n) {
    // naive approach
    int cnt = 1;
    for (int i = 2; i < n; i++) {
        cnt += gcd(i, n) == 1;
    }
    return cnt;
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d", euler(n));
}