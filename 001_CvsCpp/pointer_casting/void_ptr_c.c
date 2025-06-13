#include <stdio.h>

// C dilinde void* işaretçisi, herhangi bir türdeki işaretçiye açık dönüşüm olmadan atanabilir.
// Bu esneklik C'nin tip denetimini gevşek yapmasından kaynaklanır.

int main() {
    int x = 42;
    void* vptr = &x;        // Herhangi bir gösterici void*'a atanabilir
    int* iptr = vptr;       // void* tekrar int*'a atanabilir – C buna izin verir

    printf("Değer: %d\n", *iptr); // Çıktı: Değer: 42
    return 0;
}
