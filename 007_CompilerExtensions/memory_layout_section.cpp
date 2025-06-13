#include <cstdint>

// Veriyi özel bir linker segmentine yerleştir
__attribute__((section(".my_custom_bss")))
static uint8_t customBuffer[128]; // RAM içinde özel konum
