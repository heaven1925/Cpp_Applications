#include <iostream>
#include <string>
#include <utility> // std::move için

class Example {
public:
    std::string data;

    Example(std::string str) : data(std::move(str)) {
        std::cout << "Constructor çağrıldı, veri taşındı: " << data << std::endl;
    }

    Example(const Example& other) {
        data = other.data;
        std::cout << "Kopyalama yapıldı: " << data << std::endl;
    }

    Example(Example&& other) noexcept {
        data = std::move(other.data);
        std::cout << "Move yapıldı: " << data << std::endl;
    }
};

Example getExample() {
    return Example("Geçici Nesne"); // xvalue üretir
}

int main() {
    Example e1 = getExample(); // move constructor çağrılır

    std::string& str = e1.data;
    std::cout << "Move edilen veri: " << str << std::endl;

    return 0;
}
