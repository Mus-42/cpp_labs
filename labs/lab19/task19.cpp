#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <deque>

// Lab 19 Task 19

int main() {
    freopen("input.txt", "r", stdin);

    size_t n;
    std::cin >> n;
    std::deque<int> d(n);

    for (auto& v : d) {
        std::cin >> v;
    }

    d.erase(d.begin() + d.size() / 2);
    if (d.size() % 2 == 1) d.erase(d.begin() + d.size() / 2);


    for (auto& v : d) {
        std::cout << v;
    }
}
