#include <iostream>
#include <vector>
#include <initializer_list>

class Motor {
    int rpm;
    float voltage;
    std::vector<float> calibration;

public:
    Motor(int r, float v) : rpm(r), voltage(v) {
        std::cout << "Classic ctor\n";
    }

    Motor(std::initializer_list<float> cal) : rpm(0), voltage(0.0f), calibration(cal) {
        std::cout << "Initializer list ctor\n";
    }

    void print() const {
        std::cout << "RPM: " << rpm << ", Voltage: " << voltage << "\nCalibration: ";
        for (float f : calibration) std::cout << f << " ";
        std::cout << "\n";
    }
};

int main() {
    Motor m1{3000, 12.5f};         // classic ctor
    Motor m2{0.0f, 0.5f, 1.0f};    // initializer_list ctor
    m1.print();
    m2.print();
    return 0;
}
