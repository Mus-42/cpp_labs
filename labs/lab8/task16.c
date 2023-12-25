#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 8 Task 16

// mat size = 2n + 1
void transpose_second_diag(double* mat, int n) {
    int k = 2*n+1;
    for (int i = 0; i < k; i++)
        for (int j = i+1; j < k; j++) {
            double temp = mat[i * k + k - 1 - j];
            mat[i* k + k - 1 - j] = mat[j* k + k - 1 - i];
            mat[j* k + k - 1 - i] = temp;
        }
}

int main(void) {
    double mat[9] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    transpose_second_diag(mat, 1);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%lf ", mat[i * 3 + j]);
        putchar('\n');
    }
}