#include <iostream>

int x = 10; // global scope

void foo() {
    int x = 20; // local scope shadows global
    {
        int x = 30; // nested scope shadows upper x
        std::cout << "Inner x = " << x << "\n"; // 30
    }
    std::cout << "Function x = " << x << "\n"; // 20
}

int main() {
    foo();
    std::cout << "Global x = " << x << "\n"; // 10
    return 0;
}