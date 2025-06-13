## 🧳 Derleyiciye Bağlı Davranışlar: ID & IS

C++’ta bazı davranışlar standart tarafından tanımlanmaz, bunun yerine derleyiciye bırakılır.

### Implementation-Defined (ID)
Davranış derleyiciye bağlıdır ama belgelenmelidir.
- `int` → `unsigned int` dönüşümü
- `sizeof(struct)` padding/hizalama
- Bitfield sıralaması

### Implementation-Specified (IS)
Davranış seçeneklidir, ama derleyici sadece seçimin mantığını açıklar.
- `typeid().name()` çıktısı
- Virtual table düzeni
- Function pointer layout

### 🧠 Neden Önemli?
Farklı platformlarda farklı derleyici kullanıldığında:
- Yapı boyutları değişebilir
- Bellek hizalanması uyumsuz olabilir
- Kodun taşınabilirliği zayıflar

### 🛠️ Örnek Klasör:
Kod örnekleri için `implementation_defined_behavior/` klasörüne bakabilirsiniz.


🧳Bugün C++'ta derleyiciye bağlı davranışlar(implementation defined(ID) & implementaion specified(IS) konusunu üzerine konuşalım. C++ programlama dilinde bazı durumlarda bir kodun nasıl çalışacağı C++ standardı tarafından açıkça belirlenmez; bunun yerine davranış, kullanılan derleyiciye bırakılır. Bu tür durumlara ID (uygulama tarafından tanımlanmış) ve IS (uygulama tarafından belirlenmiş) davranışlar denir. Bu davranışlar, programın farklı platformlarda veya derleyicilerde farklı şekilde çalışmasına yol açabilir. Bu durum, hem yazılımın taşınabilirliğini hem de öngörülebilirliğini etkileyebilir.

🧩ID behavior, C++ standardının bazı detayları bilinçli olarak derleyiciye bırakmasıdır. Yani davranışın ne olacağı sabit değildir ama derleyici bunu seçer ve mutlaka belgelendirmek zorundadır. Örneğin, bir signed tamsayıyı unsigned tipe dönüştürdüğünüzde negatif değerler pozitif bir sayıya çevrilir ama bu dönüşümün tam sonucu derleyiciye bağlıdır. Derleyici, kullandığı donanıma ve mimariye göre bu davranışı belirler ve dokümantasyonuna yazar. Yani davranış sabit değildir ama tutarlıdır. Derleyici değişmediği sürece aynı sonucu verir.

🧮IS behavior durumunda derleyici belirli seçenekler arasından bir tanesini seçer, ancak kriterleri açıklamakla yetinir. Örneğin typeid().name() ifadesiyle bir sınıfın tür adını almak istediğinizde, elde edilen isim derleyiciye göre değişebilir. Bazı derleyiciler tam sınıf adını döndürürken, bazıları daha kısaltılmış isimler döndürebilir. Buradaki fark, bu davranışın sonuçtan çok, seçimin mantığını açıklama zorunluluğudur.

🔧Bu tür derleyiciye bağlı davranışlar, nesne yönelimli programlama açısından kritik bir rol oynar. Soyutlama, sınıfların ve nesnelerin bellek yerleşimi, virtual fonksiyon tablosu düzeni gibi detaylar derleyiciye göre değiştiğinde zarar görebilir. Örneğin, iki farklı derleyici aynı sınıf yapısını farklı şekilde belleğe yerleştirebilir. Bu da özellikle arayüz paylaşımı ya da dinamik yükleme gibi konularda ciddi uyumsuzluklara yol açabilir. Ayrıca, sınıf boyutları (sizeof) padding ve alignment kurallarına göre değişebilir; bu da ikili seviye uyumluluğu etkiler.

🔌 Gömülü yazılım dünyasında ise bu konu daha da kritiktir 🚨.
 Çünkü gömülü sistemlerde yazılım genellikle belirli bir donanım üzerinde doğrudan donanım register’ları ile iletişim kurar 🧠⚙️.
 Bu noktada struct’ların bellekteki yerleşimi, bit alanlarının sırası (bitfield ordering) veya endian formatı gibi detaylar doğrudan donanım davranışını etkileyebilir.
 Eğer bir struct ile bir mikrodenetleyicinin register haritası temsil ediliyorsa ve bu struct farklı derleyicilerde farklı şekilde hizalanırsa, donanım doğru çalışmayabilir ❌.
 Ayrıca, kesme servis fonksiyonlarının tanımı, bellek segmentlerinin yerleşimi, özel anahtar sözcüklerin (__attribute__, __interrupt__) kullanımı gibi pek çok detay da derleyiciye özeldir 🔍💡.