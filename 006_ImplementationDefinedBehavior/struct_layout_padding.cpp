#include <iostream>

struct A {
    char c;
    int i;
};

int main() {
    A a;
    std::cout << "Size of struct A: " << sizeof(a) << std::endl;
    return 0;
}

// ID: Struct'ların boyutu padding'e göre değişebilir
// Örneğin bazı derleyiciler struct A için 8 bayt verir, bazıları 12 verir
