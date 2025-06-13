#include <stdio.h>
#include <stdlib.h>

// C dilinde struct tipi için "struct" kelimesi her kullanımda yazılmalıdır.
// malloc dönüşü void* türündedir ve doğrudan struct işaretçisine atanabilir.

struct Point {
    int x;
    int y;
};

int main() {
    struct Point* p = malloc(sizeof(struct Point)); // geçerli

    if (p != NULL) {
        p->x = 10;
        p->y = 20;
        printf("x: %d, y: %d\n", p->x, p->y);
        free(p);
    }

    return 0;
}