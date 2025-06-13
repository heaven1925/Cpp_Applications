#include <cstdint>

// Zayıf tanımlı fallback interrupt handler
__attribute__((weak)) void Default_Handler(void) {
    while (1); // fallback döngü
}

// Naked ISR fonksiyonu (çıplak, prolog/epilog yok)
__attribute__((naked)) void TIM2_IRQHandler(void) {
    __asm volatile(
        "push {lr}      \n"
        "bl TIM2_ISR    \n"
        "pop {pc}       \n"
    );
}

// Her zaman inline olması gereken ISR mantığı
__attribute__((always_inline)) inline void TIM2_ISR(void) {
    if (MY_PERIPHERAL->STATUS & 0x01) {
        MY_PERIPHERAL->CTRL |= 0x02;
        customBuffer[0]++;
    }
}
