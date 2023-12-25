#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

// lab17 task9

class WrongCharacter: public std::invalid_argument {
public:
    WrongCharacter() : std::invalid_argument("wrong character in CharboundedString") {}
};

class CharboundedString {
public:
    CharboundedString() {}
    CharboundedString(const std::string& str, const std::string& allowed) : m_str(str), m_allowed(allowed) {
        unique_allowed();
    }
    CharboundedString(const std::string& str) : CharboundedString(str, str) {}

    size_t size() const {
        return m_str.size();
    }

    void push(char ch) {
        if (!std::binary_search(m_allowed.begin(), m_allowed.end(), ch)) {
            throw WrongCharacter();
        }
        m_str.push_back(ch);
    }
protected:
    std::string m_str;
    std::string m_allowed;

    void allowed_add(char ch) {
        auto p = std::find(m_allowed.begin(), m_allowed.end(), ch);
        if (p == m_allowed.end()) {
            m_allowed.push_back(ch);
            std::inplace_merge(m_allowed.begin(), m_allowed.end()-1, m_allowed.end());
        }
    }

    void unique_allowed() {
        std::sort(m_allowed.begin(), m_allowed.end());
        auto l = std::unique(m_allowed.begin(), m_allowed.end()) - m_allowed.begin();
        m_allowed.resize(l);
    }
};


int main() {
    auto s = CharboundedString("abc", "abcd");

    s.push('d'); // ok

    try {
        s.push('e');
    } catch(WrongCharacter& e) {
        std::cout << e.what() << std::endl;
    } 
}