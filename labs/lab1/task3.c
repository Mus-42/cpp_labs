#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 1 Task 3

int main(void) {
    char digit;
    scanf("%c", &digit);

    printf(
        "- %c - %c - %c\n"
        "%c | %c | %c\n"
        "- %c - %c - %c\n",
        digit, digit, digit, 
        digit, digit, digit, 
        digit, digit, digit
    );
}