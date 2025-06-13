## 🔍 Complete vs Incomplete Types

C++’ta incomplete (eksik) türler, yalnızca tür isminin bilindiği ama detaylarının henüz tanımlanmadığı yapılardır. Bunlar yalnızca pointer ya da reference olarak kullanılabilir. Eğer bu türden doğrudan nesne (object) oluşturulmaya çalışılırsa derleme hatası alınır.

Forward declaration, bağımlılıkları azaltmak ve derleme süresini hızlandırmak için kullanılan önemli bir tekniktir.

Kod örnekleri için: `type_completeness/` klasörüne bakınız.

C++ için temel kavramlar üzerine konuşmaya devam edelim. Başlangıç olarak; tamamlanmış (complete) ve eksik (incomplete) türler üzerine konuşalım.

🛠️ C++ dilinde tamamlanmış (complete) ve eksik (incomplete) türler, bir sınıfın (class) veya veri tipinin derleyici (compiler) tarafından tam olarak bilinip bilinmemesiyle ilgilidir. Eğer bir tür tamamlanmışsa, yani complete type ise, derleyici bu türün bellekte (memory) ne kadar yer kapladığını, hangi değişkenleri (variables) içerdiğini ve hangi fonksiyonları (functions) barındırdığını tam olarak bilir. Bu durumda, bu türden bir nesne (object) oluşturabiliriz, üye fonksiyonlarını çağırabiliriz ve değişkenlerini kullanabiliriz.

💡Ancak, bir tür eksikse (incomplete type), yani yalnızca ismi biliniyor ama detayları verilmemişse, derleyici onun bellekte ne kadar yer kapladığını bilemez. Eksik bir türü yalnızca işaretçi (pointer) veya referans (reference) olarak kullanabiliriz ama doğrudan bir nesne (object) oluşturamayız. Eksik türler genellikle ileri bildirim (forward declaration) yöntemiyle tanımlanır. Yani, bir sınıfın var olduğunu bildiririz ama içeriğini hemen tanımlamayız. Bu teknik, büyük projelerde bağımlılıkları (dependencies) azaltmak, derleme süresini (compilation time) hızlandırmak ve çevrimsel bağımlılığı (circular dependency) önlemek için kullanılır.

🔍Örneğin, A ve B adında iki sınıf düşünelim. Eğer A, B'nin içinde ne olduğunu bilmeden onun bir işaretçisini (B*) kullanacaksa, B'yi tam olarak tanımlamak yerine sadece class B; şeklinde ileri bildirim (forward declaration) yapabiliriz. Bu sayede, B sınıfının detaylarını henüz bilmesek de B* işaretçisini kullanabiliriz. Ancak, eğer A sınıfının içinde B nesnesi (B b;) oluşturmak istersek, B'nin tamamlanmış olması gerekir, aksi takdirde derleyici hata verir.
Eksik türler, bir kod parçasının başka bir dosyada (file) veya daha sonra tanımlanmasına olanak tanır. Böylece daha modüler (modular) ve düzenli (organized) bir yapı oluşturabiliriz.

📌Paylaşılan görsellerde, Incomplete Type (Eksik Tür) ve Complete Type (Tamamlanmış Tür) kavramları C++ koduyla açıklanmıştır. İlk örnekte, B sınıfı yalnızca ileri bildirim (forward declaration) ile tanımlandığından, doğrudan bir nesne (B b_obj;) oluşturulmaya çalışıldığında derleme hatası meydana gelmektedir. İkinci örnekte ise B sınıfı tamamlanmış (complete) olduğu için nesne oluşturulabilir ve program hatasız çalışır.

