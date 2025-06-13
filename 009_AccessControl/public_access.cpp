#include <iostream>

class Led {
public:
    void TurnOn() {
        std::cout << "LED ON\n";
    }

    void TurnOff() {
        std::cout << "LED OFF\n";
    }
};

int main() {
    Led l;
    l.TurnOn();   // dışarıdan erişilebilir
    l.TurnOff();  // dışarıdan erişilebilir
    return 0;
}
