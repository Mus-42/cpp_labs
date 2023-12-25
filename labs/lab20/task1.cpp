#include <iostream>
#include <string>
#include <map>

// Lab 20 Task 1

int main() {
    // let our file be open on stdin
    std::map<std::string, unsigned> nums;
    {
        std::string w;
        while (std::cin >> w) nums[w]++;
    }
    for (const auto& [w, num] : nums) {
        std::cout << w << ": " << num << std::endl;
    }
}