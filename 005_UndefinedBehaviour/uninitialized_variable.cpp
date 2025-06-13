#include <iostream>

int main() {
    int x; // ⚠️ Başlatılmamış
    std::cout << x << std::endl; // ❌ UB: tanımsız değişken kullanımı
    return 0;
}