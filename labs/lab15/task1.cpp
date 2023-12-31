#include <iostream>
#include <numeric>
#include <compare>

// Lab 15 Task 1

class Rational {
public:
    Rational() = default;
    Rational(const Rational&) = default;
    Rational(Rational&&) = default;

    Rational(int nominator, unsigned denominator) noexcept : m_nominator(nominator), m_denominator(denominator) {
        if (m_denominator == 0) {
            m_denominator = 1;
        }
        this->reduce();
    }

    Rational& operator=(const Rational&) = default;
    Rational& operator=(Rational&&) = default;

    ~Rational() = default;

    void set_nominator(int nominator) {
        this->m_nominator = nominator;
    }

    void set_denominator(unsigned denominator) {
        if (denominator != 0) {
            this->m_denominator = denominator;
        }
    }

    friend Rational operator+(const Rational&, const Rational&) noexcept;
    friend Rational operator-(const Rational&, const Rational&) noexcept;
    friend Rational operator*(const Rational&, const Rational&) noexcept;
    friend Rational operator/(const Rational&, const Rational&) noexcept;

    friend std::strong_ordering operator<=>(const Rational&, const Rational&) noexcept;

    friend std::ostream& operator<<(std::ostream&, const Rational&) noexcept;
    friend std::istream& operator>>(std::istream&, Rational&) noexcept;
protected:
    void reduce() noexcept {
        unsigned nom = std::abs(m_nominator);
        unsigned common = std::gcd(nom, m_denominator);
        m_nominator /= common;
        m_denominator /= common;
    }

    int m_nominator{0};
    unsigned m_denominator{1};
};

Rational operator+(const Rational& a, const Rational& b) noexcept {
    int nom = a.m_nominator * b.m_denominator + b.m_nominator * a.m_denominator;
    int denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator-(const Rational& a, const Rational& b) noexcept {
    int nom = a.m_nominator * b.m_denominator - b.m_nominator * a.m_denominator;
    int denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator*(const Rational& a, const Rational& b) noexcept {
    int nom = a.m_nominator * b.m_nominator;
    int denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator/(const Rational& a, const Rational& b) noexcept {
    int nom = a.m_nominator * b.m_denominator;
    int denom = a.m_denominator * b.m_nominator;
    return Rational(nom, denom);
}

std::strong_ordering operator<=>(const Rational& a, const Rational& b) noexcept {
    return a.m_nominator * b.m_denominator <=> b.m_nominator * a.m_denominator;
}

std::ostream& operator<<(std::ostream& out, const Rational& r) noexcept {
    return out << r.m_nominator << "/" << r.m_denominator;
}

std::istream& operator>>(std::istream& in, Rational& r) noexcept {
    int nom = 0;
    unsigned denom = 1;
    in >> nom >> denom;
    r = Rational(nom, denom);
    return in;
}

int main() {
    Rational sum = {};
    Rational eps = Rational(1, 1000);
    Rational neg_eps = Rational(-1, 1000);
    Rational summon = {};
    unsigned i = 0;
    do {
        i += 1;
        summon = Rational(int(i % 2) * 2 - 1, i*i);
        sum = sum + summon;
    } while(summon > eps || summon < neg_eps);
    std::cout << sum;
}
