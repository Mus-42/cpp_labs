#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// Lab 7 Task 8.f

bool is_prime(unsigned n) {
    if (n < 3 || n%2 == 0) return n == 2;
    for (unsigned i = 3; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

#define N_MAX 1024

int main(void) {
    unsigned n, primes = 0;
    unsigned arr[N_MAX];
    scanf("%u", &n);
    for (unsigned i = 0; i < n; i++) {
        scanf("%u", arr+i);
        primes += is_prime(arr[i]);
    }
    printf("primes: %u\n", primes);
}