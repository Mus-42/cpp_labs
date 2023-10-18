#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdlib.h>
#include <ctype.h>

// Lab 10 Task 3

typedef struct {
    uint16_t year;
    uint16_t month;
    uint16_t day;
} Date;

bool is_leap_year(uint16_t y) {
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

uint16_t days_in_month(uint16_t m, bool is_leap) {
    const uint8_t d[12] = {0}; // TODO
    return d[m] + (uint16_t)(is_leap && m == 1); 
}

// TODO
int main() { *(char*)0 = 0; }