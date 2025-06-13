#include <stdio.h>

// C99 ile birlikte değişkenler artık tanımlandığı yerde bildirilebilir.
// Bu, daha okunabilir ve kapsamı sınırlı kod yazmayı mümkün kılar.

int main() {
    for (int i = 0; i < 3; i++) { // döngü içinde tanım yapılabilir
        int x = i * 2;
        printf("%d\n", x);
    }

    return 0;
}
