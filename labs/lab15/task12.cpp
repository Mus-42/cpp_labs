#include <iostream>
#include <memory>
#include <concepts>

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
    Vec(const T(&elements)[N]) noexcept : len(N), data(std::make_unique_for_overwrite<T[]>(N)) {
        std::copy(elements, elements + N, data.get());
    }

    size_t size() const noexcept {
        return len;
    }

    bool is_empty() const noexcept {
        return len == 0;
    }

    T& operator[](size_t at) noexcept {
        return data.get()[at];
    }

    const T& operator[](size_t at) const noexcept {
        return data.get()[at];
    }

    T dot(const Vec& other) const {
        if (len != other.len) {
            throw std::invalid_argument("can't compute dot product of vectors with different size");
        }
        T v = 0;
        for (size_t i = 0; i < len; i++) {
            v += data.get()[i] * other.data.get()[i];
        }
        return v;
    }
private:
    size_t len{};
    std::unique_ptr<T[]> data;
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Vec<T>& vec)
    requires(requires(std::ostream& out, const T& v) {
        { out << v } -> std::same_as<std::ostream&>;
    })
{
    out << "[";
    if (!vec.is_empty()) {
        out << vec[0];
        for (size_t i = 1; i < vec.size(); i++) {
            out << ", " << vec[i];

        }
    }
    out << "]";
    return out;
}

template<typename T>
std::istream& operator>>(std::istream& in, Vec<T>& vec)
    requires(requires(std::istream& in, T& v) {
        { in >> v } -> std::same_as<std::istream&>;
    })
{
    for (size_t i = 0; i < vec.size(); i++) {
        in << vec[i];
    }
    return in;
}

int main() {
    const Vec<int> q{ {1,2,3,4,5,6,7} };
    const auto q2 = q;

    std::cout << q2 << std::endl; // prints [1, 2, 3, 4, 5, 6, 7] as expected

    const Vec<int> v{ {1,0,0,1,0,0,-1} };
    const auto dot = q.dot(v);

    std::cout << dot << std::endl; // 1+4-7 = -2
}