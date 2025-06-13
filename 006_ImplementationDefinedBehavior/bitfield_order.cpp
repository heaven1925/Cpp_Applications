#include <iostream>

struct Flags {
    unsigned int a : 1;
    unsigned int b : 1;
    unsigned int c : 2;
};

int main() {
    Flags f = {1, 1, 3};
    std::cout << "a: " << f.a << ", b: " << f.b << ", c: " << f.c << std::endl;
    return 0;
}

// ID: Bitfield sıralaması ve yerleşimi derleyiciye bağlıdır
// Donanım register'larını temsil ederken dikkatli olunmalıdır
