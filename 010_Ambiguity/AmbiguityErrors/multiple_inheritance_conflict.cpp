#include <iostream>

class A {
public:
    void init() { std::cout << "A::init()\n"; }
};

class B {
public:
    void init() { std::cout << "B::init()\n"; }
};

class C : public A, public B {
public:
    void setup() {
        // init(); ❌ Derleyici: Ambiguous!
        A::init(); // ✅ Çözüm: Açık şekilde belirt
    }
};
