#include <iostream>

class Motor {
public:
    Motor() {
        std::cout << "Motor initialized\n";
    }

    void start() {
        std::cout << "Motor started\n";
    }
};

int main() {
    Motor m;     // ✅ nesne yaratıldı
    m.start();   // çalışır
    return 0;
}
