#include <iostream>

class I2CInterface {
public:
    void init() {
        std::cout << "I2C init()\n";
    }
};

class SPIInterface {
public:
    void init() {
        std::cout << "SPI init()\n";
    }
};

// Composition: çoklu kalıtım yerine üye nesne kullanımı
class SensorDriver {
private:
    I2CInterface i2c;
    SPIInterface spi;

public:
    void InitAll() {
        i2c.init();
        spi.init();
    }
};

int main() {
    SensorDriver sensor;
    sensor.InitAll();
    return 0;
}
