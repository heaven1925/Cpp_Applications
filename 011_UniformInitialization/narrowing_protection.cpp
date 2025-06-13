int main() {
    int a = 3.14;   // ❗ Derleyici uyarmaz, a = 3 olur
    // int b{3.14}; // ❌ Derleme hatası: narrowing conversion

    unsigned int x = -10;  // ❗ silently becomes large positive
    // unsigned int y{-10}; // ❌ narrowing hatası

    return 0;
}
