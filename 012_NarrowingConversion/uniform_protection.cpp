int main() {
    // int a{3.14};     // ❌ compile-time error: narrowing
    // char b{300};     // ❌ compile-time error: narrowing

    int c = {100};    // ✅ güvenli
    unsigned int d = {-5}; // ❌ signed → unsigned narrowing

    return 0;
}
