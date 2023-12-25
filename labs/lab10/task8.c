#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 10 Task 8

typedef struct {
    double price;
    unsigned circulation;
} Magazine;

double average_cost_with_less_than10000_circulations(Magazine* magazines, size_t count) {
    double sum_cost = 0.;
    size_t sum_count = 0;
    for (size_t i = 0; i < count; i++) {
        if (magazines[i].circulation < 10000) {
            sum_cost += magazines[i].price;
            sum_count += 1;
        }
    }
    return sum_cost / sum_count;
}

int main(void) {
    // TODO usage example
}
