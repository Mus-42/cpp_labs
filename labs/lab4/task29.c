#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 4 Task 29

int is_root(int x, int n, const int* coefficients) {
    int xi = 1;
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += xi * coefficients[i];
        xi *= x;
    }
    return s == 0;
}

int solve_eq_in_integers(int n, const int* coefficients, int* roots) {
    // constant term
    int v = coefficients[0];

    // constant term - zero    
    if (v == 0) {
        *roots++ = 0; // 0 - root
        return solve_eq_in_integers(n-1, 1+coefficients, roots) + 1;
    }
    const int* roots_beg = roots;
    // non zero constant term: check divisors
    for (int i = 1; i*i <= v; i++) {
        if (v % i == 0) {
            int j = v / i;
            if (is_root(i, n, coefficients)) {
                *roots++ = i;
            }
            if (is_root(-i, n, coefficients)) {
                *roots++ = -i;
            }
            if (i != j) {
                if (is_root(j, n, coefficients)) {
                    *roots++ = j;
                }
                if (is_root(-j, n, coefficients)) {
                    *roots++ = -j;
                }
            }
        }
    }
    return roots-roots_beg;
}

int main(void) {
    // ax^3 + bx^2 + cx + d = 0 
    int coefficients[4];// d, c, b, a
    int roots[4];

    // read in reverse order
    // example input: 1 -4 -1 4
    for (int i = 0; i < 4; i++) scanf("%d", coefficients+3-i);
    
    int root_cnt = solve_eq_in_integers(4, coefficients, roots);

    printf("roots:");
    for (int i = 0; i < root_cnt; i++) {
        printf(" %d", roots[i]);
    }
    if (!root_cnt) {
        printf(" none");
    }
}