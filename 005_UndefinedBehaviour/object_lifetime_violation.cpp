#include <iostream>

struct A {
    int val;
};

int main() {
    alignas(A) char buffer[sizeof(A)];
    A* a = reinterpret_cast<A*>(buffer);

    std::cout << a->val << std::endl; // ❌ UB: nesne henüz oluşturulmadı (constructor çağrılmamış)
    return 0;
}
