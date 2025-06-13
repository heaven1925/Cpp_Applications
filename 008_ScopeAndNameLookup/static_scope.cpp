#include <iostream>

static int localVar = 20; // sadece bu dosyada geçerli

void printLocal() {
    std::cout << "LocalVar = " << localVar << std::endl;
}
