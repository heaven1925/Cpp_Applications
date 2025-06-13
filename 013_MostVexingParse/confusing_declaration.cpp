#include <iostream>

class Motor {
public:
    Motor() {
        std::cout << "Motor initialized\n";
    }
};

int main() {
    Motor m(); // ❗ Most Vexing Parse: bu bir fonksiyon bildirimi
    // m.start(); // ❌ hata: 'm' nesne değil, fonksiyon bildirimi
    return 0;
}
