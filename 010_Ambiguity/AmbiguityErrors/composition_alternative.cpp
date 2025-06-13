#include <iostream>

class I2CInterface {
public:
    void init() { std::cout << "I2C init\n"; }
};

class SPIInterface {
public:
    void init() { std::cout << "SPI init\n"; }
};

class SensorDriver {
    I2CInterface i2c;
    SPIInterface spi;

public:
    void initializeWithI2C() { i2c.init(); }
    void initializeWithSPI() { spi.init(); }
};
