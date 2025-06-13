#include "stm32f4xx.h"

// Donanıma doğrudan bağlı yapı: packed ve aligned
typedef struct __attribute__((packed, aligned(4))) {
    volatile uint32_t CTRL;
    volatile uint32_t STATUS;
    volatile uint32_t DATA;
} MyPeripheral_Type;

// Donanım register adresi
#define MY_PERIPHERAL_BASE 0x40010000
#define MY_PERIPHERAL ((MyPeripheral_Type *) MY_PERIPHERAL_BASE)
