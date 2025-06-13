## 🚨 Narrowing Conversion (NC) – C++'ta Veri Kaybı Tuzağı

### Nedir?
Daha geniş bir veri türünü daha dar bir türe dönüştürmek.
- double → int
- int → char
- signed → unsigned

### Tehlike?
- 🎯 Veri kaybı
- ❗ Sessiz taşmalar
- 🔥 Runtime hatalar

### C++11'den Sonra?
```cpp
int x{3.14};  // ❌ compile-time error
int x = 3.14; // ❗ çalışır ama veri kaybı olur


🧱 Dün C++'ta ilk değer atama yolları üzerine bir yazı paylaşmıştım. Özellikle uniform initialization yani “eş biçimli ilk değer verme” konusunu ele almıştık. Gelen yorumlar sayesinde, bu konuyla yakından ilişkili olan bir başka kavramı da keşfettim: narrowing conversions (NC) — yani daraltıcı dönüşümler.

🔍NC, daha büyük ya da daha hassas bir veri türünün, daha küçük veya daha az hassas bir türe dönüştürülmesidir. Bu dönüşüm sırasında veri kaybı yaşanabilir. C dilinde genellikle (int)x gibi explicit typecasting ile yapılır. Ancak burada gözle görünmeyen bir tehlike var: veri sessizce kesilir ya da taşar.
int x = 3.14; // narrowing: double → int (kesirli kısım kaybolur)
char c = 300; // narrowing: int → char (overflow riski)

📄C++11 ile gelen {} kullanımı yani uniform initialization, bu tarz dönüşümleri compile-time’da fark edip hata veriyor. Bu da gizli tehlikelerin daha en baştan önlenmesini sağlıyor.
int x{3.14}; // Error: NC

⚙️NC, genellikle fark edilmeden veri kaybına yol açar. Bu da runtime hatalara, beklenmeyen davranışlara ve zorlu debug süreçlerine neden olabilir. = ile yapılan klasik atamalar bunu çoğu zaman gizlerken, {} kullanımı bu tür hataları önlemeye yardımcı olur.

🏗️ Constructor’lar ile nesne oluştururken parametrelerde daraltıcı bir dönüşüm varsa, nesne beklediğiniz gibi davranmayabilir. explicit anahtar kelimesi ve {} birlikte kullanıldığında, bu risk büyük oranda azalır. Bu benim için de yeni bir kavram kod örneğinde ne olduğunu inceleyerek yorum satırlarında öğrenelim. (Görsel 1.)

🔧 İşte işin kritik olduğu yer gömülü sistemlerde kullanımıdır. Genelde uint8_t, int16_t gibi sabit boyutlu, donanım odaklı veri tipleri kullanılır. Örneğin ADC’den gelen int değeri, uint8_t olarak saklanmak istenirse, 256 üstü değerler kaybolabilir. Bu da motor sürme sinyallerinden, sensör hesaplamalarına kadar pek çok yerde hataya neden olabilir. Uniform initialization burada adeta bir emniyet kemeri gibi çalışır — yanlış dönüşüm varsa baştan yakalar. (Görsel 1.)

🧠 Sonuç olarak, küçük bir dönüşüm gibi görünse de, NC ihmale gelmez. Modern C++ bize bu tarz hataları daha yazarken fark etme şansı sunuyor. Bize düşen ise bu imkânı değerlendirmek.