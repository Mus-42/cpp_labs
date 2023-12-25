#include <list>

// Lab 19 Task 3

template<typename T>
class Poly {
public:
    Poly() noexcept = default;
    Poly(Poly&&) noexcept = default;
    Poly(const Poly&) = default;
    Poly& operator=(Poly&&) noexcept = default;
    Poly& operator=(const Poly&) = default;
    ~Poly() = default;

    // TODO input, constructor, getters
private:
    std::list<std::pair<int, T>> powers;
};

int main() {
    // TODO class usage
}