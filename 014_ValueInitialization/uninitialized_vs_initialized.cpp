#include <iostream>

struct Point {
    int x;
    int y;
};

int main() {
    Point p1;       // ❗ uninitialized → rastgele değerler
    Point p2{};     // ✅ value-initialized → x = 0, y = 0

    std::cout << "p1: " << p1.x << ", " << p1.y << "\n"; // 🧨 undefined behavior
    std::cout << "p2: " << p2.x << ", " << p2.y << "\n"; // ✅ predictable
    return 0;
}
