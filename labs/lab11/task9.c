#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Lab 11 Task 12

int main(void) {
    FILE* f = fopen("data/lab11_task9_inputs.txt", "r");
    FILE* o = fopen("out/lab11_task9_out.txt", "w");
    size_t buf_capacity = 128;
    size_t buf_i = 0;
    int* negative_nums = malloc(buf_capacity * sizeof(int));
    int num;
    while(fscanf(f, "%d", &num) == 1) {
        if (num >= 0) {
            fprintf(o, "%d", num);
        } else {
            if (buf_i == buf_capacity) {
                buf_capacity *= 2;
                negative_nums = realloc(negative_nums, buf_capacity * sizeof(int));
            }
            negative_nums[buf_i++] = num;
        }
    }
    for (size_t i = 0; i < buf_i; i++) {
        fprintf(o, "%d", negative_nums[i]);
    }
    free(negative_nums);
    fclose(f);
    fclose(o);
}