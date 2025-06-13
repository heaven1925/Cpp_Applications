#include <iostream>

int main() {
    int val = 10;

    auto x = val;     // x: int (copy)
    auto& y = val;    // y: int& (reference)

    x = 20;
    y = 30;

    std::cout << "val: " << val << ", x: " << x << ", y: " << y << "\n";
    return 0;
}
