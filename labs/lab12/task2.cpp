#include <iostream>
#include <string>
#include <charconv>

// Lab 12 Task 2


int main() {
    std::string s;
    std::getline(std::cin, s);
    uint64_t sum = 0;
    for (size_t i = 0; i + 10 <= s.size(); i += 10) {
        uint64_t num;
        std::from_chars(s.data() + i, s.data() + i + 10, num);
        sum += num;
    }

    std::cout << sum << '\n';
}
