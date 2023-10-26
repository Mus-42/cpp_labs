#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Lab 9 Task 6

typedef struct {
    size_t rows, collumns, elems_capacity;
    double* data;
} Matrix;

Matrix mat_alloc(size_t rows, size_t collumns) {
    // space for 1 extra row + collumn
    size_t capacity = rows * collumns;

    double* data = (double*)malloc(capacity * sizeof(*data));

    return (Matrix) {
        .rows = rows,
        .collumns = collumns,
        .elems_capacity = capacity,
        .data = data
    };
}

void mat_free(Matrix mat) {
    if (mat.data) {
        free(mat.data);
    }
}

Matrix mat_mul(Matrix a, Matrix b) {
    if (a.collumns != b.rows) return (Matrix) {0};
    Matrix c = mat_alloc(a.rows, b.collumns);
    // naive O(n^3) multiplication
    for (size_t i = 0; i < a.rows; i++) 
        for (size_t j = 0; j < b.collumns; j++) {
            double accum = 0.;
            for (size_t k = 0; k < b.rows; k++) {
                accum += a.data[i * a.collumns + k] * b.data[k * b.collumns + j];
            }
            c.data[i * c.collumns + j] = accum;
        }
    return c;
}

Matrix read_mat() {
    size_t n, m;
    scanf("%zu%zu", &n, &m);
    Matrix mat = mat_alloc(n, m);
    for (size_t i = 0; i < n; i++) 
        for (size_t j = 0; j < m; j++)
            scanf("%lf", mat.data + i * m + j);
    return mat;
}

int main(void) {
    size_t n;
    scanf("%zu", &n);
    Matrix accum = read_mat();
    for (size_t i = 1; i < n; i++) {
        Matrix cur = read_mat();
        Matrix prod = mat_mul(accum, cur);
        mat_free(cur);
        mat_free(accum);
        accum = prod;
    }

    for (unsigned i = 0; i < accum.rows; i++) {
        for (unsigned j = 0; j < accum.collumns; j++) {
            printf("%lf ", *(accum.data+i*accum.collumns+j));
        }
        putchar('\n');
    }

    mat_free(accum);
}