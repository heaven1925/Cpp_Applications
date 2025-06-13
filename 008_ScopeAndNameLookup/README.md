## 🎯 C++’ta Scope (Kapsam) ve Name Lookup

C++’ta her isim (değişken, fonksiyon, sınıf) bir kapsamda tanımlanır. Derleyici, bu isme erişim sırasında aşağıdaki sırayla arama yapar:

1. Local Scope → İçerideki bloklar
2. Function Scope → Etiketler
3. Class Scope → Üye değişken ve fonksiyonlar
4. Namespace Scope → Tanımlı isim alanları
5. Global Scope → Tüm program genelinde erişilebilenler

### 🔍 Name Lookup Zinciri
Bir isim tanımlandığı blokta bulunamazsa üst kapsama çıkılır. İlk eşleşen kazanır!

### 🧠 Gömülü Sistemlerde Önemli Noktalar
- `static` ile dosya içi gizleme (module-level kapsama)
- `volatile` ile donanım register’larına erişimde doğru kapsam kullanımı
- ISR içinde global erişim yerine fonksiyon parametresi tercih edilmesi

📂 Örnek dosyalar için `scope_and_name_lookup/` klasörüne bakınız.


Bugün C++'ta hem nesne yönelimli programlama (OOP)'da hem de gömülü yazılım geliştirme gibi kaynak kısıtlı ortamlarda kritik öneme sahip olan kapsam (scope) ve isim arama (name lookup) kavramları üzerine konuşalım. 

📁 C++'de scope (kapsam), bir ismin (değişken, fonksiyon, sınıf vs.) tanımlandığı ve erişilebildiği alanı ifade eder. 

En dar kapsam local scope olup, genellikle bir fonksiyon, blok ( {} ) veya döngü içerisinde tanımlanan isimlerdir ve sadece bu blok içinde geçerlidir. 
Function scope, özellikle goto komutu ile kullanılan etiketler için geçerlidir ve bir fonksiyonun tamamını kapsar. 
Class scope, bir sınıf içerisinde tanımlanan veri üyeleri ve fonksiyonlar içindir; bu kapsamda tanımlanan öğelere sınıf içinden doğrudan, dışarıdan ise nesne veya pointer yoluyla erişilir. 
Namespace scope, namespace anahtar kelimesi ile tanımlanan isim alanlarıdır ve aynı ismin farklı modüllerde çakışmadan kullanılmasını sağlar. 
Son olarak, global scope, herhangi bir fonksiyon, sınıf veya namespace dışında tanımlanan isimlerin tüm dosyada (veya extern ile başka dosyalarda) erişilebilir olduğu kapsamdır. 

📸 Bu kapsamlar ile ilgili kod örnekleri görselde verilmiştir.

🔎 Name Lookup ise, derleyicinin bir ismin neyi temsil ettiğini (hangi değişkeni, fonksiyonu vb.) bulma işlemidir. Bu kapsamlar derleyicinin isim arama (name lookup) sürecinde sırasıyla kontrol edilir; bir isim önce yerel kapsamda aranır, bulunamazsa daha geniş kapsamlar sırayla kontrol edilir. C++'ta bu işlem "kapsam zinciri" üzerinden yukarı doğru yapılır.

Eğer bir isim yerel kapsamda bulunamazsa, bir üst kapsama, orada da yoksa daha üst kapsam(lar)a bakılır. Bu işlem, isim bulunduğunda durur (first match wins). Derleyici önce yerel kapsamda arama yapar, bulunamazsa sırasıyla çevreleyen bloklara, sınıfa, namespace’e ve global scope’a çıkar. Kalıtım varsa base class’lara, using bildirimi varsa ilgili namespace’lere de bakılır. Hiçbir kapsamda bulunamazsa "undefined identifier" hatası verir.

Gömülü yazılım geliştirme dünyasında, RAM, ROM ve işlemci zamanı gibi kaynaklar sınırlı olduğu için kapsam ve isim arama mekanizmasının doğru anlaşılması, hem performans hem de bakım açısından kritik önem taşır.
📁 Gereksiz global değişken kullanımı, isim çakışmalarına ve bellek yönetim sorunlarına yol açabilir.
🧩 static tanımlar ile dosya içi kapsam sınırlandırması yapılabilir.
🧠 Donanım register’larına erişimde volatile ve doğru kapsam kullanımı hatasız, deterministik sistem davranışı için şarttır.
🔄 ISR fonksiyonlarında kapsam dışı isimlere erişimden kaçınmak gerekir.
Bu nedenle, kapsam ve name lookup konuları, sadece derleyici düzeyinde değil, gerçek zamanlı, güvenilir sistemlerin mimarisi için de temel yapı taşlarından biridir.