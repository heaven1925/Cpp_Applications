#include <iostream>

int globalTick = 0;

void tickHandler() {
    globalTick++; // global scope değişken erişimi
}
