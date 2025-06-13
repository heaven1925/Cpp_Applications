#include <iostream>

int* createDanglingPointer() {
    int x = 42;
    return &x; // ⚠️ UB: x stack'te tanımlı, fonksiyon bitince yok olacak
}

int main() {
    int* ptr = createDanglingPointer();
    std::cout << *ptr << std::endl; // ❌ Undefined Behavior
    return 0;
}
