#include <iostream>
#include <cstdint>

uint16_t readADC() {
    return 1023; // örnek ADC değeri
}

int main() {
    uint16_t adcVal = readADC();
    uint8_t safeVal1 = static_cast<uint8_t>(adcVal); // ❗ 255 üzeri değer kesilir

    // uint8_t safeVal2{adcVal}; // ❌ compile error with uniform init if narrowing occurs

    std::cout << "ADC: " << adcVal << ", Truncated: " << static_cast<int>(safeVal1) << "\n";
    return 0;
}
