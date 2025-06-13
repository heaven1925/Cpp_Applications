#include <stdio.h>

// C dilinde sabit değerler genellikle #define ile tanımlanır.
// Bu makrolar derleyici tarafından sadece metin olarak yerine konur.
// Tip güvenliği ve kapsam (scope) kontrolü yoktur.

#define PI 3.14159
#define SQUARE(x) ((x) * (x)) // Parantez dikkat edilmezse hata oluşabilir

int main() {
    double r = 2.0;
    double area = PI * SQUARE(r); // area = πr²

    printf("Alan: %.2f\n", area); // Çıktı: Alan: 12.57
    return 0;
}