#include <iostream>
#include <climits>

int main() {
    int max = INT_MAX;
    int result = max + 1; // ❌ UB: signed integer overflow
    std::cout << result << std::endl;
    return 0;
}
