#include <iostream>

void printRvalue(int&& num) { // Rvalue referans alır
    std::cout << "Rvalue olarak alınan değer: " << num << std::endl;
}

int main() {
    int y = 10 + 5; // 10 + 5 ifadesi bir rvalue'dir
    std::cout << "Hesaplanmış rvalue: " << y << std::endl;

    // printRvalue(y); // ❌ Hata: y bir lvalue'dir
    printRvalue(30);       // ✅ Geçici değer doğrudan geçebilir
    printRvalue(5 + 10);   // ✅ rvalue ifadesi

    int&& r = 42;          // rvalue referans bir geçici değeri tutar
    std::cout << "Rvalue referansı tutan değişken: " << r << std::endl;

    return 0;
}
