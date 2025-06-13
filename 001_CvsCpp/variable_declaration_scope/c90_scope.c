#include <stdio.h>

// C90'da tüm değişkenler blokların başında tanımlanmalıdır.
// Döngü içinde tanımlama yapılamaz (çoğu derleyici desteklese de standart değildir).

int main() {
    int i; // tüm değişkenler başta tanımlanmalı

    for (i = 0; i < 3; i++) {
        int x = i * 2; // C90'da bu tanım bazı derleyicilerde uyarı verebilir
        printf("%d\n", x);
    }

    return 0;
}
