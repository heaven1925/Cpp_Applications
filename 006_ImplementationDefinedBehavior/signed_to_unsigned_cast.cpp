#include <iostream>
#include <limits>

// ID: signed tamsayıdan unsigned'a dönüşüm
int main() {
    int neg = -1;
    unsigned int converted = static_cast<unsigned int>(neg);

    std::cout << "Signed: " << neg << std::endl;
    std::cout << "Converted to unsigned (ID behavior): " << converted << std::endl;

    return 0;
}

// Derleyiciye bağlı olarak, -1 değeri unsigned dönüşümünde farklı sonuçlar verebilir (örneğin 4294967295)
