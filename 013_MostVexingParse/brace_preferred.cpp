#include <iostream>

class Sensor {
public:
    Sensor(int id) {
        std::cout << "Sensor #" << id << " created\n";
    }
};

int main() {
    Sensor s1(5);   // ✅ Çoğu zaman doğru ama MVP tehlikesi var
    Sensor s2{5};   // ✅ Kesinlikle nesne: C++11 sonrası önerilen sözdizimi
    return 0;
}
