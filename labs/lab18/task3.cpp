#include <vector>
#include <string>
#include <iostream>

// in this implementation ve are wery lucky and "random" element from problem statement is always last element

template<typename T>
class BlackBox {
public:
    BlackBox() noexcept = default;

    bool is_empty() const noexcept {
        return m_storage.empty();
    }

    void push(const T& el) {
        m_storage.push_back(el);
    }

    void push(T&& el) {
        m_storage.push_back(el);
    }

    void pop() {
        m_storage.pop_back();
    }

    const T& xpop() const {
        return m_storage.back();
    }
private:
    std::vector<T> m_storage;
};

int main() {
    BlackBox<int> bb;
    bb.push(42);

    std::cout << bb.xpop() << std::endl;
}