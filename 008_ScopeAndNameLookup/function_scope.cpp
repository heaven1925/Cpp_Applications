void test() {
    int x = 5;

label1:
    x++;
    if (x < 10)
        goto label1; // ✅ label sadece bu fonksiyonda geçerli
}
