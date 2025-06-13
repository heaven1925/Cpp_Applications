#include <iostream>

int main() {
    int x = 3.14;     // ❗ double → int (kesir kaybolur)
    char c = 300;     // ❗ int → char (overflow riski)

    std::cout << "x: " << x << "\n"; // x: 3
    std::cout << "c: " << static_cast<int>(c) << "\n"; // platforma göre değişebilir

    return 0;
}
