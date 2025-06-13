## ⚠️ Ambiguity (Çift Anlamlılık) Hataları – C++

C++ derleyicisi aynı isme sahip birden fazla seçenekle karşılaştığında ve hangisinin kastedildiğini anlayamadığında "ambiguous" hatası verir.

### Neden Olur?
- Çoklu kalıtım ile aynı isimli fonksiyonlar gelir
- using bildirimi ile adlar çakışır
- overload ve template kombinasyonları karışır

### Nasıl Çözülür?
- Açıkça belirtin → `A::foo()` veya `Logger::init()`
- Çoklu kalıtım yerine composition (iç içe kullanım) tercih edin

### Gömülü Sistemlerde Önemi:
- Ambiguity derleme zamanı hatasıdır ama tasarım zayıflığının göstergesidir
- ISR, HAL veya abstraction layer’larda açık yapı gereklidir
- Donanım konfigürasyonunda ambiguity sonucu kritik zaman hatalarına yol açabilir

📂 Örnekler için `ambiguity_in_inheritance/` klasörünü inceleyin.


C++'ta kod yazarken bazen öyle bir noktaya geliyoruz ki derleyici bize “Sen burada ne yapmak istediğini sanıyorsun?” diye bakıyor adeta. İşte bu anlardan biri, ambiguity yani çift anlamlılık hatasıyla tanıştığımız an. Bu hata, derleyicinin aynı isimli birden fazla şey bulup “Hangisini kast ettiğini anlamadım” dediği durumlarda karşımıza çıkıyor. Ve inanın, kodda doğru şeyi yapmış olsanız bile, derleyici bu ikilemde kalırsa size acımasız davranıyor: Hata veriyor!

🎯 Ambiguity hataları genelde çoklu kalıtım (multiple inheritance), aynı isimde fonksiyonlar veya bazen using decleration yüzünden oluşur. Yani siz
“Yukarıdan gelen class içindeki foo() fonksiyonunu çağırayım” 
dersiniz ama üst classlarda iki farklı foo() varsa, derleyici 
“Hangi foo?” 
diye sorar. Ve maalesef siz söylemeden o kendi karar veremez.

🧬Şimdi diyelim ki A ve B clasından kalıtım alan bir C clası yazdın. Hem A'da hem B'de foo() diye bir fonksiyon var. Sen C classından bir nesne üretip obj.foo() dersen... işte orada C++ kafayı yer. 
“A'nın mı foo'su, B'nin mi? Söyle de rahatlayayım” der. Ve bu noktada derleme hatası alırsın.
Bu yüzden OOP'de çoklu kalıtımı dikkatli kullanmak gerekiyor. Hatta bu yüzden çoğu "modern mimari composition" yani classları birbirinin içine nesne olarak yerleştirme yöntemini tercih ediyor. Yani 
"Miras alacağına arkadaş ol" mantığı. (Görsel 1.)

🔧 Gömülü sistemlerde işler basit olmalı; az RAM, sınırlı işlem gücü ve genellikle gerçek zamanlı çalışan sistemler var. Bu yüzden kodda belirsizlik hiç istenmez. Ambiguity, yani çift anlamlılık hatası, burada hem zaman kaybına hem de performans sorunlarına yol açabilir. Özellikle donanım soyutlama katmanlarında (HAL) farklı arayüzlerden gelen aynı isimli fonksiyonlar varsa, classlar arasında net bir yapı kurulmadıysa, derleyici hangisinin çağrılması gerektiğini bilemez. Sonuç: derleme hatası

Bir SensorDriver classı yazıyoruz. Bu sürücü hem I2CInterface hem de SPIInterface sınıflarından kalıtım alıyor. Her iki arayüzde de init() fonksiyonu var. Şimdi SensorDriver içinde doğrudan init(); dersen… C++ durur, çünkü hangi init() fonksiyonunu çağıracağını bilemez. Bu ambiguity hatası, özellikle gömülü tarafta donanım ilk konfigürasyonunu yapmaya çalışırken sistemi kilitleyebilir. Çözüm? I2CInterface::init(); veya SPIInterface::init(); diyerek açık şekilde belirtmen gerekir. 
Ama daha temiz bir yöntem arıyorsak? İşte burada composition devreye girer. (Görsel 2.)

📌 Sonuç Olarak, C++’ta ambiguity hatası aslında derleyicinin bize 
“Şeffaf ol, karışıklık yaratma” dediği bir uyarıdır. 
Özellikle OOP mimarilerde ve gömülü yazılım projelerinde bu hataları önceden düşünmek, hem temiz kod yazar hem de başımız ağrımaz. Unutma, derleyici senin dostundur; sadece açık olmanı ister. 😄
