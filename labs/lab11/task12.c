#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 11 Task 12

int main(void) {
    FILE* f = fopen("data/lab11_task12_inputs.txt", "r");
    char name_buf[256];
    while(!feof(f)) {
        int cost, age_from, age_to;
        if (fscanf(f, "%s%d%d%d", name_buf, &cost, &age_from, &age_to) != 4) {
            break;
        }
        // find all for 5 y.o. cheaper than 1000 uah 
        if (age_to <= 5 && cost <= 1000) {
            printf("%s\n", name_buf);
        }
    }
}