#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lab 4 Task 31

// a^n
int ipow(int a, int n) {
    int res = 1, i = 0;
    while (n) {
        if (n & 1<<i) {
            n &= n-1;
            res *= a;
        }
        a *= a;
        i++;
    }
    return res;
}

// naive floor(a^(1/n)) using binary search
int i_nth_root(int a, int n) {
    int ans = 0;
    int i = 30 / n + 1; // max msb index
    while (i--) {
        ans ^= 1<<i;
        if (ipow(ans, n) > a) {
            ans ^= 1<<i;
        } 
    }
    return ans;
} 

#define MAX_X 1<<16 // something like ceil(sqrt(INT_MAX))  
#define MAX_ANS_LEN 128

int x[MAX_X];

int xi_sum = 0;
int m;
// brute-force
int choose_xi(int max_x, int rem_depth) {
    if (rem_depth <= 1) {
        for (int i = 1; i <= max_x; i++) {
            if (xi_sum + x[i] == m) {
                printf("%d", i);
                return 1; // found 
            }
        }
        return 0; // not found 
    }
    
    // iterate in reverse order
    for (int i = max_x; i > 0; i--) {
        xi_sum += x[i];
        int found = xi_sum < m && choose_xi(i, rem_depth-1);
        xi_sum -= x[i];
        if (found) {
            printf(" %d", i);
            return 1;
        }
    }

    return 0; // not found
}

int main(void) {
    int d;
    // d > 1, m >= 1
    scanf("%d%d", &d, &m);

    // x[i] <= floor(m^(1/d))
    int max_x = i_nth_root(m, d);

    for (int i = 1; i <= max_x; i++) {
        // compute powers once
        x[i] = ipow(i, d);
    }

    // brute force all possible combinations for given depth i
    for (int i = 1; i <= MAX_ANS_LEN; i++) {
        if (choose_xi(max_x, i)) {
            printf("\nin total: %d number(s)\n", i);
            return 0;
        }
    }
    printf("not found: length limit reached");
}