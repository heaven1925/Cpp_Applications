#include <iostream>
#include <cstdint>

struct PWM_Config {
    uint32_t frequencyHz;
    uint8_t dutyCyclePct;
    bool invertedOutput;

    void apply() const {
        std::cout << "PWM CONFIG: "
                  << frequencyHz << "Hz, "
                  << static_cast<int>(dutyCyclePct) << "%, "
                  << (invertedOutput ? "Inverted" : "Normal") << "\n";
    }
};

int main() {
    PWM_Config config{20000, 75, false};  // ✅ güvenli, anlaşılır
    config.apply();

    // PWM_Config wrongConfig{750.5f, 130, true}; // ❌ Derleme hatası
    return 0;
}
