#include <iostream>

class A {
public:
    void foo() {
        std::cout << "A::foo()\n";
    }
};

class B {
public:
    void foo() {
        std::cout << "B::foo()\n";
    }
};

// Ambiguity: Hem A'dan hem B'den gelen aynı isimli fonksiyon
class C : public A, public B {
};

int main() {
    C obj;
    // obj.foo(); // ❌ Ambiguity: Hangi foo?
    obj.A::foo(); // ✅ Çözüm: Belirtmek gerekiyor
    obj.B::foo();
    return 0;
}
