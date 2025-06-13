## 💣 Undefined Behavior in C++

Undefined Behavior (UB), C++ standardında sonucu tanımlanmamış durumları ifade eder.
Kod düzgün derlenebilir, çalışabilir, ama sonuç belirsizdir.

### Yaygın UB Senaryoları:
- 🕳️ Dangling Pointer (Silinmiş belleğe erişim)
- 📦 Uninitialized Variable Read
- ➕ Signed Integer Overflow
- 🚫 Array sınırları dışına çıkmak
- 🧵 Data Race (eşzamanlı yazma/okuma)
- ⏳ Object Lifetime Violation (henüz oluşturulmamış objeye erişim)

### UB’ye Karşı Ne Yapmalı?
- `-fsanitize=undefined` gibi runtime checker’lar kullan
- `clang-tidy`, `cppcheck` gibi static analiz araçları uygula
- MISRA C++, AUTOSAR C++ ve CERT C++ gibi güvenli kod standartlarına uy

### Gömülü Sistemlerde UB Tehlikesi:
UB, bellek erişimi kritik olan sistemlerde cihazın donmasına, kilitlenmesine veya resetlenmesine neden olabilir. ISR içindeki UB durumları geri dönüşü olmayan hatalara yol açabilir.

📂 Örnek kodlar için `undefined_behavior/` klasörüne bakınız.


🎯 Bugün C++'de tanımsız davranış - undefined behaviour ya da kısaca UB üzerine konuşalım.
Undefined Behavior, C++ standardına göre bir ifadenin sonucu için dil standardının herhangi bir garantide bulunmadığı durumdur. Yani, derleyicinin bu durumda her şeyi yapmasına izin verilir:
 🚫 runtime hatası vermeyebilir,
 ❌ yanlış sonuç üretebilir veya
 💥 sessizce çökebilir.
 Hatta bazı durumlarda kodun tamamen ortadan optimize edilmesine bile sebep olabilir 🧨.

UB'nin olabileceği başlıca sebepler:
🕳️ Dangling pointer access (ör. silinmiş belleğe erişim)
🚫 Out-of-bounds array access
➕ Signed integer overflow
📦 Uninitialized variable read
🧵 Data race in multi-threaded code
⏳ Violating object lifetimes
📸 Bunların her biriyle ilgili kısa örnekler görsel olarak eklenmiştir.

🏗️ OOP mimarisinde UB'nin yeri ayrı önemlidir. Polymorphism kullanılırken object slicing ya da invalid downcasting UB’ye neden olabilir. Destructor’ları olmayan soyut sınıf pointer'ları ile yapılan delete işlemleri UB'dir (virtual destructor gereklidir). VTable manipülasyonu veya reinterpret_cast ile yapılan yanlış sınıf dönüşümleri UB doğurur. Bu hatalar, soyutlamayı ihlal eder ve OOP'nin temel avantajı olan bakımı kolay, genişletilebilir yapıyı bozar.

📜 UB'den kaçınmak için bazı aksiyonlar alabiliriz. Static analysis tools kullanmak (ör. clang-tidy, cppcheck), Compiler warnings ve -fsanitize=undefined gibi runtime check'ler gerçekleştirmek ve MISRA C++ veya CERT C++ gibi coding standard'larına uymalıyız.

🔌Bu konuya gömülü sistemler açısından bakmak gerekirse, Donanım seviyesinde bellek adreslerine izinsiz erişim, peripheral registerlarına zarar verebilir. ISR içinde UB oluşursa, sistem kilitlenebilir veya reset gerekebilir. UB kaynaklı hatalar genellikle deterministik değildir, bu da gerçek zamanlı sistemlerde tahmin edilemeyen davranışlara yol açar. Derleyici, UB oluştuğunu varsayarak kodu agresif şekilde optimize eder ve bu da beklenmedik donanımsal etkiler doğurabilir.

💣Sonuç olarak, C++’da undefined behavior, görünmez bir tehlike gibidir: kod doğru çalışıyor gibi görünse bile, bir gün gömülü sisteminiz sahada garip ve maliyetli hatalarla dönebilir. Özellikle donanımın doğrudan kontrol edildiği, bellek erişiminin kritik olduğu gömülü uygulamalarda UB'ye sıfır tolerans yaklaşımı gereklidir.