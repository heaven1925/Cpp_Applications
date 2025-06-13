#include <iostream>
#include <string>
#include <vector>

int main() {
    int a{42}; // ✅ güvenli
    std::string s{"Hello"}; // ✅
    std::vector<int> v{1, 2, 3}; // ✅

    std::cout << "a = " << a << ", s = " << s << "\n";
    for (int i : v) std::cout << i << " ";
    return 0;
}
