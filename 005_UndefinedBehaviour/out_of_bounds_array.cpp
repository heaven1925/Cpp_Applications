#include <iostream>

int main() {
    int arr[3] = {1, 2, 3};
    std::cout << arr[5] << std::endl; // ❌ UB: sınır dışı erişim
    return 0;
}
