#include <stdio.h>

// C99 ile gelen restrict anahtar kelimesi, bir işaretçinin gösterdiği belleğe
// sadece bu işaretçiyle erişileceğini garanti eder.
// Derleyici bu garanti sayesinde daha agresif optimizasyonlar yapabilir.

void add_arrays(int* restrict a, int* restrict b, int* restrict result, int size) {
    for (int i = 0; i < size; ++i) {
        result[i] = a[i] + b[i]; // restrict sayesinde overlap olmayacağı varsayılır
    }
}

int main() {
    int arr1[3] = {1, 2, 3};
    int arr2[3] = {4, 5, 6};
    int sum[3];

    add_arrays(arr1, arr2, sum, 3);

    for (int i = 0; i < 3; ++i)
        printf("%d ", sum[i]); // Çıktı: 5 7 9

    return 0;
}
