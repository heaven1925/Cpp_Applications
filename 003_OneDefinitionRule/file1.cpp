#include "header.h"

// globalVar değişkeninin TANIMI — sadece bir yerde olmalı
int globalVar = 42;

// MyClass üyesinin fonksiyon tanımı
void MyClass::show() {
    std::cout << "MyClass::show() fonksiyonu çalıştı!" << std::endl;
}

int main() {
    MyClass obj;
    obj.show();

    printMessage(); // Inline fonksiyon çağrısı

    std::cout << "Global değişken: " << globalVar << std::endl;

    return 0;
}
