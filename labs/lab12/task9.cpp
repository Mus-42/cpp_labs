#include <cmath>
#include <fstream>

// Lab 12 Task 9

int main() {
    constexpr const char* input_file = "data/lab12_Task9_inputs.txt";
    constexpr const char* output_file = "data/lab12_Task9_outputs.txt";

    std::ifstream in(input_file);
    std::ofstream out(output_file);

    int num;
    in >> num;
    while(true) {
        if (in.eof()) {
            out << num;
            break;
        }
        int num2;
        in >> num2;
        if (num > num2) {
            out << num * num;
        } else {
            out << num;
        }
        num = num2;
    }
}
