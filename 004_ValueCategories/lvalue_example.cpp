#include <iostream>

void modifyLvalue(int& ref) { // Lvalue referans alır
    ref = 42; // Lvalue olan değişkeni değiştirir
}

int main() {
    int x = 10; // x bir lvalue'dir çünkü bellekte bir adresi vardır
    std::cout << "Başlangıç değeri: " << x << std::endl;

    x = 20; // Yeni değer atanabilir
    std::cout << "Yeni değer: " << x << std::endl;

    modifyLvalue(x); // x, lvalue olarak referansa geçebilir
    std::cout << "Fonksiyon çağrısından sonra: " << x << std::endl;

    return 0;
}
