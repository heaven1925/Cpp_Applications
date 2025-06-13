## 🔐 Access Control (Erişim Kontrolü) – C++

C++’ta erişim belirleyicileri, bir sınıfın üyelerine (veri ve fonksiyonlar) dışarıdan kimlerin erişebileceğini belirler. Bu, hem güvenli nesne yönelimi hem de donanım güvenliği için kritiktir.

### Erişim Türleri:
| Belirleyici | Açıklama |
|-------------|----------|
| `public`    | Her yerden erişilebilir. API fonksiyonları için uygundur |
| `private`   | Sadece sınıfın içinden erişilebilir. Veri gizliliği için kullanılır |
| `protected` | Sınıf ve alt sınıflar erişebilir. Kalıtım için uygundur |

### Encapsulation (Kapsülleme)
Erişim kontrolü, bir sınıfın iç yapısını dış dünyadan saklayarak sadece tanımlı yollarla kullanılmasını sağlar.

### Gömülü Sistemlerde Neden Önemlidir?
- `private`: Donanım register adreslerini dış dünyadan gizler
- `public`: Sadece gerekli API fonksiyonlarını açık bırakır
- `protected`: Genişletilebilirliği korurken donanım soyutlamasını bozar

📂 Örnekler için `access_control/` klasörüne göz atabilirsiniz.


C++ konuşmaya devam edelim. Bugün Nesne yönelimli programlamanın temel taşlarından biri olan kavram üzerine konuşacağız. Erişim kontrolü-Access Control; bir sınıfın üyelerine (veri veya fonksiyon) başka sınıflar, fonksiyonlar veya kullanıcılar tarafından ne ölçüde erişilebileceğini belirler. 3 ana erişim düzeyi vardır:

✅ public
Her yerden erişilebilir.
Kullanıcı arabirimi gibi dış dünyaya açık fonksiyonlar burada yer alır.
Kütüphane API’si gibi davranır.
🔒 private
Yalnızca sınıfın kendisi erişebilir.
Nesnenin iç durumu burada gizlenir.
Encapsulation (kapsülleme) sağlar.
⚠️ protected
Yalnızca sınıfın kendisi ve türeyen (inherited) sınıflar erişebilir.
Genellikle kalıtım senaryolarında kullanılır.

🧠 Erişim kontrolü, OOP’nin üç temel ilkesinden biri olan Encapsulation (kapsülleme) için gereklidir. Bir nesnenin iç verileri rastgele dışarıdan değiştirilebilirse, o nesnenin "geçerli" bir durumda kalması garanti edilemez.
🧰 Örnek: Kapsüllenmemiş Kod
motor.currentSpeed = 100; // Tehlikeli, çünkü doğrudan erişim var
✅ Kapsüllenmiş Kod
motor.SetSpeed(100); // İçerde limit kontrolü yapılabilir.

Gömülü yazılım geliştirme, doğrudan donanım ile etkileşim kurulan, kaynakları sınırlı ve genellikle gerçek zamanlı çalışan sistemler üzerinde gerçekleştirilir. Bu bağlamda, C++’te erişim kontrolü (access control) sadece nesne yönelimli tasarımın bir unsuru değil, aynı zamanda sistemin güvenilirliğini ve kararlılığını sağlayan temel bir mekanizmadır.

Donanım bileşenleriyle etkileşimde bulunan sürücü sınıfları, genellikle volatile donanım register’larına erişim içerir ve bu erişimler kritik öneme sahiptir. Bu gibi sınıflarda private erişim belirleyicisiyle donanım adresleri gibi hassas üyeleri dış dünyadan gizlemek, dışarıdan yapılabilecek kontrolsüz veya hatalı erişimleri engeller.

Ayrıca gömülü sistemlerde zaman deterministikliği önemlidir; yani bir işlemin ne kadar sürede tamamlanacağı önceden bilinir olmalıdır. public arayüzler yalnızca gerekli olan fonksiyonları açıkta tutarak, sistem davranışını kontrol altına almayı sağlar. Kodun sadece belirlenen yollarla erişilebilmesi, hem hata ayıklamayı kolaylaştırır hem de güvenlik açısından sistemin yüzey alanını daraltır. Bu yapı, aynı zamanda modülerliği de destekler; sürücüler, protokol yığınları veya üst katman uygulamaları gibi katmanlar, kendi iç mantıklarını gizleyerek, dışarıya yalnızca kullanılması gereken fonksiyonları sunar. Böylece her modül, kendi iç yapısını koruyarak yeniden kullanılabilir, test edilebilir ve gerektiğinde değiştirilebilir hâle gelir. Gömülü yazılımda erişim kontrolü, sadece yazılımsal bir tasarım tercihi değil, sistemin kararlılığı ve sürdürülebilirliği için vazgeçilmez bir gerekliliktir.