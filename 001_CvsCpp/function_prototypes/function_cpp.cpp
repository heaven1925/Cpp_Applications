#include <iostream>

// C++ dilinde fonksiyonlar çağrılmadan önce bildirilmelidir.
// Aksi takdirde derleme hatası alınır.

int topla(int a, int b); // Önceden bildirim (Function Prototype)

int main() {
    std::cout << topla(3, 4) << std::endl; // Bildirildiği için doğru kullanım
    return 0;
}

int topla(int a, int b) { // Fonksiyonun tanımı
    return a + b;
}
