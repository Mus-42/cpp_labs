#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <charconv>
#include <system_error>

// Lab 14 task 16

int main() {
    freopen("data/lab14_task16.txt", "r", stdin);
    freopen("data/lab14_task16_out.txt", "w", stdout);

    std::string buf;
    std::cout << std::setprecision(10);

    while (!std::cin.eof()) {
        std::cin >> buf;
        double num{};
        auto [_ptr, ec] = std::from_chars(buf.data(), buf.data()+buf.size(), num);
        if (ec == std::errc::invalid_argument || num < 0.) {
            std::cout << buf << ' ';
        } else {
            std::cout << std::log(num) << ' ';
        }
    }
}