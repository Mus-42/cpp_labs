#include <algorithm>
#include <iostream>
#include <vector>
#include <type_traits>
#include <concepts>

// Lab 21 Task 17

template<std::input_iterator It1, std::input_or_output_iterator It2, typename F>
void for_each(const It1 beg1, const It1 end1, It2 beg2, [[maybe_unused]] It2 end2, F&& f) {
    std::transform(beg1, end1, beg2, beg2, std::move(f));
}

int main() {
    int a[3] = {1, 2, 3};
    int b[3] = {4, 5, 6};

    for_each(a, a+3, b, b+3, [](int a, int b) { return a + b; });

    for (auto v : b) {
        std::cout << v << ' ';
    }
}