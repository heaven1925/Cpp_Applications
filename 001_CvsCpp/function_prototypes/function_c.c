#include <stdio.h>

// C dilinde fonksiyon bildirimi zorunlu değildir.
// Derleyici, fonksiyonu görmeden çağırmaya izin verir.
// Ancak bu durum modern derleyicilerde uyarı üretebilir.

int main() {
    printf("%d\n", topla(3, 4)); // Bildirilmeden çağrılıyor
    return 0;
}

int topla(int a, int b) { // Fonksiyonun tanımı burada yapılır
    return a + b;
}
