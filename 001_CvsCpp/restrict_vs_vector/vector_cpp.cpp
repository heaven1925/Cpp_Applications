#include <iostream>
#include <vector>

// C++ dilinde restrict anahtar kelimesi yoktur.
// Bunun yerine std::vector gibi container'lar bellek yönetimi ve optimizasyon açısından güvenli yapılar sunar.

void add_vectors(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& result) {
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] + b[i]; // overlap riski yok, referansla verildiği için güvenlidir
    }
}

int main() {
    std::vector<int> arr1 = {1, 2, 3};
    std::vector<int> arr2 = {4, 5, 6};
    std::vector<int> sum(3); // boyut önceden ayarlanmalı

    add_vectors(arr1, arr2, sum);

    for (int x : sum)
        std::cout << x << " "; // Çıktı: 5 7 9

    return 0;
}
