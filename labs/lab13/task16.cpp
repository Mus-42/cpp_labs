#include <string_view>
#include <cctype>
#include <vector>

// Lab 13 Task 16

std::vector<std::string_view> find_all_words_starting_with(std::string_view s, char first) {
    std::vector<std::string_view> ret{};

    while (!s.empty()) {
        if (s.front() != first) {
            while (!s.empty() && !std::isspace(static_cast<unsigned char>(s.front()))) s.remove_prefix(1);
            while (!s.empty() && std::isspace(static_cast<unsigned char>(s.front()))) s.remove_prefix(1);
            break;
        }
        size_t len = 0;
        while (len < s.size() && !std::isspace(static_cast<unsigned char>(s[len]))) len++;
        ret.push_back(s.substr(0, len));
        s.remove_prefix(len);
        while (!s.empty() && std::isspace(static_cast<unsigned char>(s.front()))) s.remove_prefix(1);
    }

    return ret;
}

int main() {
    auto a = find_all_words_starting_with("abc efg aqr", 'a');
}