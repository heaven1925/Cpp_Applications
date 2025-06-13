#include "header.h"

// Ayrı bir çeviri biriminde inline fonksiyon ve extern değişken erişimi

void someFunction() {
    std::cout << "someFunction çalışıyor..." << std::endl;
    printMessage(); // Inline fonksiyon ODR gereği burada da çağrılabilir
}

int main() {
    someFunction();

    // globalVar burada tanımlanmamış, ama bildirimi var, bu nedenle erişilebilir
    std::cout << "Global değişken file2.cpp içinde: " << globalVar << std::endl;

    return 0;
}
