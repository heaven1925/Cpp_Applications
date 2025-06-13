#include <iostream>

// 🧩 Incomplete Type (Eksik Tür) — Sadece bildirim yapılmış
class B; // forward declaration

class A {
private:
    B* b_ptr; // ✅ Incomplete Type yalnızca pointer olarak kullanılabilir

public:
    A();
    void setB(B* b);
    void print();
};

// ✅ Complete Type — B sınıfı tanımlanıyor
class B {
private:
    int value;

public:
    B(int v) : value(v) {}
    int getValue() const { return value; }
};

// A'nın metodları tanımlanıyor
A::A() : b_ptr(nullptr) {}

void A::setB(B* b) {
    b_ptr = b;
}

void A::print() {
    if (b_ptr)
        std::cout << "B'nin değeri: " << b_ptr->getValue() << std::endl;
    else
        std::cout << "B nesnesi atanmadı!" << std::endl;
}

int main() {
    B b(42);          // ✅ Complete type olduğu için nesne oluşturulabilir
    A a;
    a.setB(&b);       // A sınıfına B'nin adresi veriliyor
    a.print();        // Çıktı: B'nin değeri: 42
    return 0;
}
