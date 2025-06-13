#include <iostream>

class Motor {
public:
    Motor(int speed) {
        std::cout << "Speed: " << speed << "\n";
    }
};

int main() {
    Motor m1(3.14);     // ❗ çalışır ama değer kaybı olur
    // Motor m2{3.14};  // ❌ compile error with narrowing

    return 0;
}
