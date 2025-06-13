#include <iostream>
#include <cstdlib> // malloc, free için

// C++ dilinde struct türleri doğrudan adlarıyla kullanılabilir (struct yazmaya gerek yok).
// Ayrıca malloc dönüşü void* olduğu için cast (dönüştürme) yapılmalıdır.

struct Point {
    int x;
    int y;
};

int main() {
    Point* p = (Point*) std::malloc(sizeof(Point)); // cast zorunlu (C tarzı)

    if (p != nullptr) {
        p->x = 10;
        p->y = 20;
        std::cout << "x: " << p->x << ", y: " << p->y << std::endl;
        std::free(p);
    }

    return 0;
}
