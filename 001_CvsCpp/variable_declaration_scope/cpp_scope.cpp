#include <iostream>

// C++ da C99 gibi değişkenleri tanımlandığı yerde tanımaya izin verir.
// Ayrıca for döngülerinde doğrudan kullanılabilir ve kapsam içinde sınırlıdır.

int main() {
    for (int i = 0; i < 3; ++i) {
        int x = i * 2;
        std::cout << x << std::endl;
    }

    // std::cout << i; // ❌ Hatalı: 'i' sadece for döngüsü içinde tanımlıdır

    return 0;
}
