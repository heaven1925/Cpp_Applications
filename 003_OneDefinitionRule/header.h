#ifndef HEADER_H
#define HEADER_H

#include <iostream>

// Değişken bildirimi — ODR gereği yalnızca bir çeviri biriminde tanımı olmalı
extern int globalVar;

// Inline fonksiyon — Tüm çeviri birimlerinde aynı olmalı
inline void printMessage() {
    std::cout << "Hello, ODR!" << std::endl;
}

// Sınıf tanımı — Tüm çeviri birimlerinde birebir aynı olmalı
class MyClass {
public:
    void show();
};

#endif // HEADER_H
