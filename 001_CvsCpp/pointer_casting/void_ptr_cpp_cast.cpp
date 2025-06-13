#include <iostream>

// C++ dilinde void* doğrudan başka türlere atanamaz.
// Tür güvenliğini artırmak için explicit (açık) cast gereklidir.

int main() {
    int x = 42;
    void* vptr = &x;

    // int* iptr = vptr;          // ❌ Derleme hatası: doğrudan atanamaz
    int* iptr = static_cast<int*>(vptr); // ✅ C++: Güvenli cast kullanılır

    std::cout << "Değer: " << *iptr << std::endl; // Çıktı: Değer: 42
    return 0;
}
