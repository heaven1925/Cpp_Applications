## 🔄 Value Categories in Modern C++

C++’ta değer kategorileri bellekteki konum, ömür ve kaynak yönetimi açısından önemli bilgiler sağlar. En sık karşılaşılan kategoriler:

- 🏠 `lvalue`: Kalıcı adresi olan, değiştirilebilir (örnek: değişkenler)
- 🎈 `rvalue`: Geçici, adresi olmayan, taşınabilir (örnek: 3 + 5, "metin")
- 📦 `xvalue`: Geçici + sahipliği el değiştirecek (örnek: std::move ile taşınan nesneler)

Bu değer türleri aşağıdaki gibi kullanılır:

| Tür      | Referans Türü   | Örnek Kullanım                  |
|----------|------------------|---------------------------------|
| lvalue   | `T&`             | `void foo(int& x)`              |
| rvalue   | `T&&`            | `void foo(int&& x)`             |
| xvalue   | `std::move(t)`   | `T&& r = std::move(obj)`        |

Kod örnekleri `value_categories/` klasöründedir.


Bugün C++'de bilinen bir diğer kavram olan değer katagorileri (Value Categories) üzerine konuşalım. C++'te değer kategorileri, ifadelerin bellekte nasıl saklandığını, ömürlerini ve nasıl kullanılabileceklerini belirleyen bir kavramdır. Özellikle bellek yönetimi, performans optimizasyonu ve move semantics gibi konular için kritik öneme sahiptir.

🧠 Bu kategorilerden en yaygın olanları lvalue (sol değer), rvalue (sağ değer) ve xvalue (expiring value – tükenen değer) olarak sınıflandırılır. Lvalue'ler bellekte belirli bir adrese sahip olup değiştirilebilirken, rvalue'ler genellikle geçici değerlere sahip olup doğrudan bir adresi olmayan ifadelerdir. Xvalue ise, bellekte bir kaynağa sahip olmasına rağmen yakında geçersiz hale gelecek nesneleri ifade eder ve move semantics ile ilişkilidir. Bu üç kategori, özellikle modern C++’ta kaynak yönetimi ve performans optimizasyonu açısından kritik bir rol oynar.

Lvalue (Sol Değer) 🏠📌 → Kalıcı, bellekte adresi var, değiştirilebilir. 
Bellekte kalıcı olarak bir adresi bulunan ve doğrudan erişilebilen değerlere verilen isimdir. Bu tür değerler, atama işlemlerinin sol tarafında yer alabilir ve genellikle değişkenler veya nesneler olarak kullanılır. Örn, int x = 10; ifadesindeki x bir lvalue’dür çünkü bellekte bir adresi vardır ve değeri değiştirilebilir. Lvalue ifadeleri, fonksiyon parametreleri olarak kullanılabilir ve referanslar aracılığıyla başka fonksiyonlara iletilebilir. (Görsel 1.)

Rvalue (Sağ Değer) 💨🎈 → Geçici, anlık kullanılan, taşıma işlemleri için uygun.
Bellekte kalıcı bir adresi olmayan ve genellikle geçici olarak oluşturulan değerlerdir. Atama işlemlerinin sol tarafında kullanılamazlar çünkü doğrudan erişilebilir bir adresleri yoktur. Örneğin, int y = 10 + 5; ifadesindeki 10 + 5 işleminin sonucu bir rvalue’dür çünkü hesaplandıktan sonra bir değişkende saklanmadığı sürece kullanılamaz. C++11 ile birlikte gelen && rvalue referansları, move semantics kullanarak verimli bellek yönetimi ve performans optimizasyonu sağlamaya olanak tanır. (Görsel 2.)

Xvalue (Expiring Value) 🔄📦 → Tüketilecek, move işlemleri için uygun.
Bellekte bir kaynağa sahip olmasına rağmen, yakında geçersiz olacak değerlere verilen isimdir. Genellikle move işlemleriyle ilişkilendirilir ve kaynakların taşınması için kullanılır. Örneğin, std::string && str = std::move(getString()); ifadesindeki std::move(getString()) bir xvalue üretir, çünkü getString() fonksiyonunun dönüş değeri artık mevcut nesneye ait değildir ve başka bir nesneye taşınabilir. Xvalue’lar, kaynakları gereksiz kopyalamalar olmadan verimli bir şekilde yönetmek için önemlidir. (Görsel 3.)

🛠️Değer kategorileri, Move constructor ve move assignment ile gereksiz kopyalamaları önleyerek bellek tüketimini azaltır ve kodun hızını artırır. Ayrıca, lvalue ve rvalue için farklı fonksiyon overload yaparak esneklik sağlar. Yanlış kullanım, gereksiz kopyalamalara, bellek israfına ve tanımsız davranışlara (undefined behavior) yol açabilir. 🚀