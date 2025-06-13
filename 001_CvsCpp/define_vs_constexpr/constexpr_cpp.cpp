#include <iostream>

// C++ dilinde sabitler const veya constexpr ile tanımlanır.
// Bu yaklaşım tip güvenliği, derleme zamanı kontrolü ve kapsam avantajı sağlar.

constexpr double PI = 3.14159;

constexpr double square(double x) {
    return x * x;
}

int main() {
    double r = 2.0;
    double area = PI * square(r); // Derleme zamanı hesaplama

    std::cout << "Alan: " << area << std::endl; // Çıktı: Alan: 12.5664
    return 0;
}
