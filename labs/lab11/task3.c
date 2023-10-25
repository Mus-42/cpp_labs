#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Lab 11 Task 3

int main(void) {
    char f_filename[256];
    char g_filename[256];

    scanf("%255s", f_filename);
    scanf("%255s", g_filename);

    FILE* f_file = fopen(f_filename, "wb");
    FILE* g_file = fopen(g_filename, "wb");

    int num;
    while (scanf("%d", &num) == 1 && num != 0) {
        fwrite(&num, sizeof(int), 1, f_file);
        // TODO implement correct condition for g file
        if (num % 2 == 0) {
            fwrite(&num, sizeof(int), 1, g_file);
        }
    }

    fclose(f_file);
    fclose(g_file);
}