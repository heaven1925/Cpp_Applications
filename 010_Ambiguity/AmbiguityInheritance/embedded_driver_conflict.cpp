#include <iostream>

class I2CInterface {
public:
    void init() {
        std::cout << "[I2C] initialized\n";
    }
};

class SPIInterface {
public:
    void init() {
        std::cout << "[SPI] initialized\n";
    }
};

// Gömülü sistemde ambiguity hatasına örnek
class SensorDriver : public I2CInterface, public SPIInterface {
public:
    void Initialize() {
        // init(); // ❌ Ambiguity: Hangi init?
        I2CInterface::init(); // ✅ açıkça belirtilmeli
        SPIInterface::init();
    }
};

int main() {
    SensorDriver sd;
    sd.Initialize();
    return 0;
}
