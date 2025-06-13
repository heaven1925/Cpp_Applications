#include <iostream>

class Fan {
private:
    bool isOn = false;

public:
    void Power(bool state) {
        if (state && !isOn) {
            isOn = true;
            std::cout << "Fan turned ON\n";
        } else if (!state && isOn) {
            isOn = false;
            std::cout << "Fan turned OFF\n";
        }
    }
};

int main() {
    Fan f;
    f.Power(true);  // doğru yol
    // f.isOn = true; ❌ kapsülleme ihlali
    return 0;
}
