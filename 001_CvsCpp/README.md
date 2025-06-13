# C vs C++: Derinlemesine Farklar ve Modern Yaklaşımlar

Bu repo, C ve C++ dillerinin temel farklarını ve C kodlarının C++ diline nasıl uyarlanması gerektiğini örneklerle gösterir.

## İçerikler

- Fonksiyon Bildirimi ve Prototipleme
- Typecasting ve `void*` Kullanımı
- `struct`, `malloc`, `NULL` vs `nullptr`
- `restrict` vs `std::vector`
- `#define` vs `constexpr`
- Değişken Tanımlama Kuralları (C90, C99, C++)
- Derleyici davranışları ve OOP geçiş notları

## Notlar
Kodlarda her fark yorum satırı ile açıklanmıştır. C ve C++ için karşılaştırmalı örnekler verilmiştir.

LINKED-IN YAZISI

C++ üzerine konuşmaya devam ediyoruz. Bugün C Dili ve C++ içindeki C Dili üzerine konuşalım. 

C'den C++'a geçiş, prosedürel programlamadan nesne yönelimli programlamaya (OOP) adım atmak anlamına gelir. C++ dilinde sınıflar (class), nesneler (object), kapsülleme (encapsulation), kalıtım (inheritance) ve çok biçimlilik (polymorphism) gibi özellikler eklenerek daha modüler ve yeniden kullanılabilir kod yazılmasını sağlar. Ayrıca, new ve delete gibi dinamik bellek yönetim mekanizmaları ve std::vector, std::string gibi standart kütüphane bileşenleri, C’deki malloc ve free fonksiyonlarına daha güvenli alternatifler sunar. Derleyiciler C kodlarını C++ derleyicisiyle derleyebilir, ancak C++'ın daha katı kuralları nedeniyle bazı C kodlarının uyarlanması gerekir.

C dilinde fonksiyonlar prototip tanımlanmadan çağrılabilir ve derleyici varsayılan olarak bu fonksiyonun int döndüreceğini varsayabilir (implicit int). Ancak C++’ta her fonksiyon çağrılmadan önce prototip tanımlanmalıdır, aksi takdirde derleme hatası alınır. Ayrıca, C’de void function(); ifadesi, fonksiyonun herhangi bir sayıda parametre alabileceğini gösterirken, C++’ta aynı ifade fonksiyonun kesinlikle parametre almadığını belirtir. Eğer C’de bir fonksiyonun hiç parametre almadığını açıkça ifade etmek istiyorsak, void function(void); şeklinde yazmamız gerekir.

C++'ta typecasting C'ye kıyasla daha sıkıdır ve daha güvenli hale getirilmiştir.
C dilinde, bir void* türü herhangi bir başka türdeki işaretçiye (int*, char*, struct* vb.) doğrudan atanabilir çünkü C'de işaretçilerin tür denetimi daha esnektir. Ancak, C++’ta bu güvenlik açığını önlemek için void* türü doğrudan bir başka işaretçiye atanamaz ve açık dönüşüm (cast) gereklidir. (Görsel 2.)

C’de geçerli olup C++’ta geçersiz olan bazı yapılar vardır. Örneğin, C’de struct isimleri küresel ad alanında yer alırken, C++’ta struct bir tür olarak doğrudan kullanılabilir (struct MyStruct yerine MyStruct). Ayrıca, C’de malloc ile döndürülen void* türü doğrudan bir göstericiye atanabilirken, C++’ta açık tür dönüşümü (cast) gereklidir. C++’ta NULL yerine nullptr kullanımı teşvik edilir ve makro tabanlı hashtag#define yerine const veya constexpr gibi dil seviyesinde sabitler önerilir. 

📌 C ve C++ dilleri birbirine oldukça yakın olsa da, bazı ifadelerin bağlamı farklılık gösterebilir. Örneğin, C90 standardında fonksiyonlar prototipsiz çağrılabiliyordu ve derleyici bu durumda int dönüş türünü varsayardı; ancak bu özellik C99 ile kaldırılmıştır ve C++’ta geçerli değildir. Benzer şekilde auto anahtar kelimesi C’de sadece bir storage class olarak tanımlanırken, C++’ta type deduction amacıyla kullanılır. const her iki dilde bulunsa da, C++'ta constexpr, consteval ve constinit gibi genişletilmiş sözdizimi ile daha güçlü derleme zamanı ifadeler sağlanır. 

Bu nedenle, iki dilde aynı görünen anahtar kelimelerin arkasında farklı kurallar ve davranışlar olabilir; bu farkların net olarak anlaşılması, teknik doğruluk açısından oldukça önemlidir.
