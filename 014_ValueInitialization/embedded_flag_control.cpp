#include <cstdint>
#include <iostream>

struct SystemState {
    bool ready{};
    uint8_t errorCode{};
    int32_t calibrationValue{};
};

void printState(const SystemState& s) {
    std::cout << "Ready: " << s.ready << ", Error: " << static_cast<int>(s.errorCode)
              << ", Cal: " << s.calibrationValue << "\n";
}

int main() {
    SystemState state{}; // ✅ tüm alanlar sıfırlanır (value-init)

    printState(state);

    // if (state.ready) { ... } → predictable control path
    return 0;
}
