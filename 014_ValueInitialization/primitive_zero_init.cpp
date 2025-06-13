#include <iostream>

int main() {
    int a{};       // ✅ value-initialization → a = 0
    double b{};    // ✅ b = 0.0
    char c{};      // ✅ c = '\0'

    std::cout << "a = " << a << ", b = " << b << ", c = " << static_cast<int>(c) << "\n";
    return 0;
}
