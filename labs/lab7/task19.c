#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

// Lab 7 Task 19

// Compute poly from roots
// coefficients, tmp_buf - bufs (all of them at least roots_n+1 size)
void compute_poly(int roots_n, const double* roots, double* coefficients, double* tmp_buf) {
    double *const out_buf = coefficients;
    double* tmp_1 = coefficients;
    double* tmp_2 = tmp_buf;

    tmp_1[0] = 1;

    for (int i = 1; i <= roots_n; i++) {
        // tmp_2 = tmp_1 * (x - roots[i])
        
        memset(tmp_2, 0, (i+1) * sizeof(double));
        for (int j = 0; j < i; j++) {
            tmp_2[j] -= tmp_1[j] * roots[i-1]; 
            tmp_2[j+1] += tmp_1[j]; 
        }

        // swap buffers
        double* tmp = tmp_1;
        tmp_1 = tmp_2;
        tmp_2 = tmp;
    }

    if (tmp_1 != out_buf) {
        for (int i = 0; i <= roots_n; i++) {
            out_buf[i] = tmp_1[i];
        }
    }
}

int main(void) {
    // Up to 100 roots
    int n;
    double roots[100], coefficients[128], tmp_buf[128];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", roots + i);
    }
    
    compute_poly(n, roots, coefficients, tmp_buf);

    printf("%lf ", coefficients[0]);
    for (int i = 1; i <= n; i++) {
        printf(" + %lf * x^%d", coefficients[i], i);
    }

    putchar('\n');
}