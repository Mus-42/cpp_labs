#include <iostream>
#include <memory>

// Lab 15 task 12

template<typename T>
class Vec {
public:
    Vec() noexcept = default;
    Vec(Vec&&) noexcept = default;
    Vec& operator=(Vec&&) noexcept = default;
    Vec(const Vec& other) noexcept : len(other.len), data(std::make_unique_for_overwrite<T[]>(other.len)) {
        std::copy(other.data.get(), other.data.get() + other.len, data.get());
    }
    Vec& operator=(const Vec& other) noexcept {
        len = other.len;
        data = std::make_unique_for_overwrite<T[]>(other.len);
        std::copy(other.data.get(), other.data.get() + other.len, data.get());
    }
    
    ~Vec() = default;

    template<size_t N>
    Vec(const T (&elements)[N]) noexcept : len(N), data(std::make_unique_for_overwrite<T[]>(N)) {
        std::copy(elements, elements + N, data.get());
    }

    size_t size() const noexcept {
        return len;
    }

    T& operator[](size_t at) noexcept {
        return data.get()[at];
    }
    
    const T& operator[](size_t at) const noexcept {
        return data.get()[at];
    }
private:
    size_t len{};
    std::unique_ptr<T[]> data;
};

int main() {
    Vec<int> q{{1,2,3,4,5,6,7}};
    auto q2 = q;

    for (size_t i = 0; i < q2.size(); i++) {
        std::cout << q2[i] << ' ';
    }
}