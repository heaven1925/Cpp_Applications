#include <cstdint>
#include <iostream>

// Fonksiyonun özel hizalanması
__attribute__((aligned(16))) void process_aligned_data() {
    // SIMD, DMA işlemleri için hizalı veri kullanımı
    std::cout << "Aligned işlem yapıldı." << std::endl;
}
