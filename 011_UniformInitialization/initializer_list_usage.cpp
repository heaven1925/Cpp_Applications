#include <iostream>
#include <vector>

void printAll(std::initializer_list<int> list) {
    for (int v : list) std::cout << v << " ";
    std::cout << "\n";
}

int main() {
    printAll({1, 2, 3, 4}); // ✅ initializer list sayesinde kısa ve net
    return 0;
}
