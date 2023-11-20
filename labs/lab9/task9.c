#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Lab 9 Task 9.п

typedef struct {
    size_t rows, collumns, elems_capacity;
    double* data;
} Matrix;

Matrix mat_alloc(size_t rows, size_t collumns) {
    // space for 1 extra row + collumn
    size_t capacity = (rows + 1) * (collumns + 1);

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

void mat_flush(Matrix* mat) {
    if (!mat->data) return;
    const double eps = 1e-9;
    size_t r = 0;
    for (size_t i = 0; i < mat->rows; i++) {
        bool is_empty = true;
        for (size_t j = 0; j < mat->collumns; j++) {
            is_empty &= fabs(mat->data[mat->collumns * i + j]) < eps;
        }
        if (!is_empty) {
            if (r != i) {
                memcpy(mat->data + mat->collumns * r, mat->data + mat->collumns * i, sizeof(*mat->data) * mat->collumns);
            }
            r++;
        }
    }
    mat->rows = r;
}

int main(void) {
    size_t n, m;
    scanf("%zu%zu", &n, &m);

    Matrix mat = mat_alloc(n, m);
    for (unsigned i = 0; i < mat.rows; i++)
        for (unsigned j = 0; j < mat.collumns; j++) {
            scanf("%lf", mat.data+i*mat.collumns+j);
        }

    mat_flush(&mat);

    for (unsigned i = 0; i < mat.rows; i++) {
        for (unsigned j = 0; j < mat.collumns; j++) {
            printf("%lf ", *(mat.data+i*mat.collumns+j));
        }
        putchar('\n');
    }
    
    mat_free(mat);
}