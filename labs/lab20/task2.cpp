#include <iostream>
#include <set>

// Lab 20 Task 2

int main() {
    size_t n;
    std::cin >> n;

    std::set<int> s;
    for (size_t i = 0; i < n; i++) {
        int v;
        std::cin >> v;
        s.insert(v);
    }

    while (s.size() > 1) {
        std::set<int> s0;
        auto iter = s.begin();
        int prev = *iter++;
        while (iter != s.end()) {
            int cur = *iter++;
            s0.insert(cur + prev);
            prev = cur;
        }
        s = std::move(s0);
    }

    // assume that s not empty
    std::cout << *s.begin() << std::endl;
}