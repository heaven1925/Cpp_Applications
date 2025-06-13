#include <iostream>

// ❌ Hatalı Kullanım: Sadece ileri bildirim (forward declaration) yapılmış
class B;

class A {
private:
    B b_obj; // ❌ HATA: Incomplete type doğrudan nesne olarak kullanılamaz!
};

int main() {
    A a; // ❌ Derleme hatası burada oluşur
    return 0;
}

// 🧯 Derleyici hatası: ‘b_obj’ has incomplete type ‘B’
