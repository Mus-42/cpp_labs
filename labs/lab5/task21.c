#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 5 Task 21

// coin_value should be sorted
// return value: is possible split into coins
// required_coins_count - how to split
int split_ammount(int ammount, int coins_count, const int* coin_value, const int* max_available_count, int* required_coins_count) {
    // greed algorithm should work here
    int i = coins_count;
    while (i--) {
        int n = ammount / coin_value[i];
        // if coins ammount is limited
        if (n > max_available_count[i]) {
            n = max_available_count[i];
        }
        required_coins_count[i] = n;
        ammount -= coin_value[i] * n;
    }
    return ammount == 0; // if not 0 - cant split with this coin values or available coins
}

#define COINS_COUNT 6
const int coin_value[COINS_COUNT] = { 1, 2, 5, 10, 25, 50 };

int main(void) {
    // a) 
    int ammount;
    scanf("%d", &ammount);
    const int wallet_coins_count[COINS_COUNT] = { 1, 2, 5, 1, 0, 1 }; // coins in wallet (for now predefined)
    int required_coins_count[COINS_COUNT];
    int is_possible_a = split_ammount(ammount, COINS_COUNT, coin_value, wallet_coins_count, required_coins_count);

    if (is_possible_a) {
        printf("a) split possible. required count: %d", required_coins_count[0]);
        for (int i = 1; i < COINS_COUNT; i++) {
            printf(", %d", required_coins_count[i]);
        }
        putchar('\n');
    } else {
        puts("a) split impossible: not enough coins in wallet");
    }

    // b) split *large* number into coins
    const int unlimited_wallet[COINS_COUNT] = { 1 << 30, 1 << 30, 1 << 30, 1 << 30, 1 << 30, 1 << 30 };

    int is_possible_b = split_ammount(ammount, COINS_COUNT, coin_value, unlimited_wallet, required_coins_count);
    if (is_possible_b) {
        printf("b) split possible. required count: %d", required_coins_count[0]);
        for (int i = 1; i < COINS_COUNT; i++) {
            printf(", %d", required_coins_count[i]);
        }
        putchar('\n');
    } else {
        // unreachable?
        puts("b) split impossible");
    }
}