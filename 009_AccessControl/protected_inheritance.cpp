#include <iostream>

class Base {
protected:
    void SayHello() {
        std::cout << "Hello from Base\n";
    }
};

class Derived : public Base {
public:
    void CallHello() {
        SayHello(); // ✅ protected olduğu için erişilebilir
    }
};

int main() {
    Derived d;
    d.CallHello(); // çalışır
    // d.SayHello(); ❌ doğrudan çağrılamaz
    return 0;
}
