#include <iostream>

class Motor {
public:
    Motor() {
        std::cout << "Motor initialized\n";
    }
};

int main() {
    Motor m{}; // ✅ value initialization → default ctor çağrılır
    return 0;
}
