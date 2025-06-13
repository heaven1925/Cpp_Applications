#include <iostream>

namespace Sensor {
    int value = 42;
    void read() {
        std::cout << "Sensor: " << value << "\n";
    }
}

namespace Actuator {
    int value = 100;
    void read() {
        std::cout << "Actuator: " << value << "\n";
    }
}

int main() {
    Sensor::read();
    Actuator::read();
    return 0;
}
