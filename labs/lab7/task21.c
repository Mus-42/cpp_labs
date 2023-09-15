#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// Lab 7 Task 21

int a[1024];

int main(void) {
    int n;
    // n elements in array, 1 <= n <= 1024
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }

    // Something similar to insertion sort
    // Works in O(n^2)
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }

    if (n % 2 == 0) {
        double median = (a[n/2] + a[n/2-1]) / 2.;
        printf("median: %.1lf\n", median); 
    } else {
        printf("median: %d\n", a[n/2]);
    }
}