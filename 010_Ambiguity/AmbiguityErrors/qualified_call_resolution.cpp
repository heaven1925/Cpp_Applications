#include <iostream>

class I2CInterface {
public:
    void init() { std::cout << "I2C init\n"; }
};

class SPIInterface {
public:
    void init() { std::cout << "SPI init\n"; }
};

class SensorDriver : public I2CInterface, public SPIInterface {
public:
    void initializeSensor() {
        // init(); ❌ Ambiguous
        I2CInterface::init(); // ✅ Açık seçicilik
    }
};
