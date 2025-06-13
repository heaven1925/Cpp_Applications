class GpioBase {
public:
    void Set() {
        *ODR |= pinMask;
    }

    void Reset() {
        *ODR &= ~pinMask;
    }

protected:
    void InitPin(volatile uint32_t* odrAddr, uint32_t pin) {
        ODR = odrAddr;
        pinMask = pin;
    }

private:
    volatile uint32_t* ODR = nullptr;
    uint32_t pinMask = 0;
};

class LedDriver : public GpioBase {
public:
    void Init() {
        InitPin(reinterpret_cast<uint32_t*>(0x48000014), (1 << 5)); // GPIOA Pin5
    }

    void BlinkOnce() {
        Set();
        // delay(100);
        Reset();
    }
};
