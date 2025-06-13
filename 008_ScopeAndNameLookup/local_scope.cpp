#include <iostream>

void myFunction() {
    int a = 10; // local scope
    if (true) {
        int b = 20; // scope sadece if bloğu
        std::cout << "a + b = " << a + b << "\n"; // ✅ erişilebilir
    }
    // std::cout << b; ❌ hata: b burada tanımsız
}
