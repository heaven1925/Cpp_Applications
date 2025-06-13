#include <iostream>
#include <typeinfo>

class MyClass { };

int main() {
    MyClass obj;
    std::cout << "typeid(obj).name(): " << typeid(obj).name() << std::endl;
    return 0;
}

// IS: typeid().name() çıktısı derleyiciye göre farklılık gösterebilir
// g++: "7MyClass", MSVC: "class MyClass", Clang: "MyClass" gibi
