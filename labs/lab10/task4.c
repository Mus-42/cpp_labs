#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Lab 10 Task 4

typedef struct {
    int numerator;
    unsigned denumerator;
} Rational;

inline Rational rat_from_int(int num) {
    return (Rational) { num, 1 };
}

inline void rat_display(Rational rat) {
    printf("%d/%u", rat.numerator, rat.denumerator);
}

inline Rational rat_simplify(Rational rat) {
    // TODO
    return rat;
}

inline Rational rat_add(Rational a, Rational b) {
    b.numerator *= a.denumerator;
    a.numerator *= b.denumerator;
    a.denumerator *= b.denumerator;
    a.numerator += b.numerator;
    return rat_simplify(a);
}

inline Rational rat_sub(Rational a, Rational b) {
    b.numerator *= a.denumerator;
    a.numerator *= b.denumerator;
    a.denumerator *= b.denumerator;
    a.numerator -= b.numerator;
    return rat_simplify(a);
}

inline Rational rat_mul(Rational a, Rational b) {
    a.numerator *= b.numerator;
    a.denumerator *= b.denumerator;
    return rat_simplify(a);
}

inline Rational rat_div(Rational a, Rational b) {
    a.denumerator *= b.numerator;
    a.numerator *= b.denumerator;
    return rat_simplify(a);
}

inline int rat_cmp(Rational a, Rational b) {
    if (a.numerator == b.numerator && a.denumerator == b.denumerator) return 0;
    // TODO
    return -1;
}

int main(void) {
    // TODO
}
