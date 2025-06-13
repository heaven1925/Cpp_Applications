#include <cstdint>
#include <iostream>

volatile uint8_t* ADC_RESULT = reinterpret_cast<volatile uint8_t*>(0x4001204C);

int main() {
    // ❌ auto burada tehlikeli olabilir: int mi? uint8_t mi? pointer mı?
    // auto result = *ADC_RESULT;  // tür: uint8_t, ama beklenmeyen promotion olabilir

    // ✅ Güvenli olan:
    uint8_t result = *ADC_RESULT;

    std::cout << "ADC result: " << static_cast<int>(result) << "\n";
    return 0;
}
