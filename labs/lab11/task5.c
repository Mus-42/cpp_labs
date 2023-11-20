#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Lab 11 Task 5

typedef struct {
    size_t deg;
    double coeff;
} Monome;

typedef struct {
    size_t n;
    Monome* monomes;
} Poly;

Poly input_poly() {
    Poly p = {0};

    scanf("%zu", &p.n);

    p.monomes = (Monome*)calloc(p.n, sizeof(Monome));

    for (size_t i = 0; i < p.n; i++) {
        scanf("%zu", &p.monomes[i].deg);
        scanf("%lf", &p.monomes[i].coeff);
    }

    return p;
}

void write_poly(Poly poly, FILE* file) {
    fwrite(&poly.n, sizeof(size_t), 1, file);
    fwrite(poly.monomes, sizeof(Monome), poly.n, file);
}

Poly read_poly(FILE* file) {
    Poly p = {0};
    fread(&p.n, sizeof(size_t), 1, file);
    p.monomes = (Monome*)calloc(p.n, sizeof(Monome));
    fread(p.monomes, sizeof(Monome), p.n, file);
    return p;
} 

void free_poly(Poly p) {
    free(p.monomes);
}

int main(void) {
    {
        Poly p = input_poly();
        FILE* f = fopen("poly.dat", "wb");
        write_poly(p, f);
        fclose(f);
        free_poly(p);
    }

    {
        FILE* f = fopen("poly.dat", "wb");
        Poly p = read_poly(f);
        fclose(f);
        free_poly(p);
    }
}