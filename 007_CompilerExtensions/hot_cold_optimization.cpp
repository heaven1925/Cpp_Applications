#include <iostream>

// Sık kullanılan fonksiyon (sıcak bölge)
__attribute__((hot)) void critical_function() {
    std::cout << "Kritik işlem yapıldı." << std::endl;
}

// Nadiren çağrılan fonksiyon (soğuk bölge)
__attribute__((cold)) void rarely_used_function() {
    std::cout << "Hata yönetimi fonksiyonu." << std::endl;
}
