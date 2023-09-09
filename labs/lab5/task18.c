#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 5 Task 18

int seq_next(int num, int k, int* n) {
    int buf[12];
    int i = 0;
    while (num) {
        buf[i++] = num % 10;
        num /= 10;
    }
    if (i == 0) {
        buf[i++] = 0;
    }
    if (k <= i) {
        *n = buf[i - k];
        return k;
    } else {
        return i;
    }
}

int tenpow_k(int k) {
    int v = 1, n;
    while (k) {
        k -= seq_next(v, k, &n);
        v *= 10;
    }
    return n;
}

int natural_k(int k) {
    int v = 1, n;
    while (k) {
        k -= seq_next(v, k, &n);
        v += 1;
    }
    return n;
}

int square_k(int k) {
    int v = 1, n;
    while (k) {
        k -= seq_next(v * v, k, &n);
        v += 1;
    }
    return n;
}

int fib_k(int k) {
    if (k == 1) return 0;
    if (k == 2) return 1;
    k -= 2;
    int n, a = 0, b = 1;
    while (k) {
        int c = a + b;
        a = b;
        b = c;
        k -= seq_next(c, k, &n);
    }
    return n;
}

int main(void) {
    int k;
    scanf("%d", &k);

    // all sequenses works correct for first 55 digits
    // then integer type overflows for tenpow & fib

    printf("a) tenpow_k = %d\n", tenpow_k(k));
    printf("b) natural_k = %d\n", natural_k(k));
    printf("c) square_k = %d\n", square_k(k));
    printf("d) fib_k = %d\n", fib_k(k));

    printf("all fist k members of seq (using same function digit by digit)\n");

    printf("\na) tenpow: \n");
    for (int i = 1; i <= k; i++) {
        printf("%d", tenpow_k(i));
    }
    printf("\nb) natural: \n");
    for (int i = 1; i <= k; i++) {
        printf("%d", natural_k(i));
    }
    printf("\nc) square: \n");
    for (int i = 1; i <= k; i++) {
        printf("%d", square_k(i));
    }
    printf("\nd) fib: \n");
    for (int i = 1; i <= k; i++) {
        printf("%d", fib_k(i));
    }
}