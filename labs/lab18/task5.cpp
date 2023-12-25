#include <iostream>
#include <concepts>
#include <type_traits>

// Lab 18 Task 5

template<typename T, size_t N>
struct Array {
    T arr[N];

    template<typename K, std::enable_if_t<std::is_invocable_r_v<unsigned, K, T>, bool> = true>
    void bucket_sort(K to_key);
};

template<typename T, size_t N>
template<typename K, std::enable_if_t<std::is_invocable_r_v<unsigned, K, T>, bool>>
void Array<T, N>::bucket_sort(K to_key) {
    // TODO sort elements in each bucket using counting sort by key and then merge buckets together
}

int main() {
    Array<int, 5> a{1, 5, 2, 4, 3};

    a.bucket_sort([](int a){ return a; });
}