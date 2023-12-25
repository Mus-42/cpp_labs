#include <iostream>

// Lab 19 Task 1

int main() {
    unsigned n;
    std::cin >> n;
    unsigned i_min = 0;
    double t0 = 0., t_min = 1e9;
    for (unsigned i = 0; i < n; i++) {
        double t;
        std::cin >> t;
        t0 += t;
        if (t_min > t0) {
            t_min = 0;
            i_min = i;
        }
        std::cout << t0 << ' ';
        t0 -= 1.;
    }
    std::cout << std::endl << i_min + 1;
}