## 📌 One Definition Rule (ODR)

ODR, C++'ta her değişken, fonksiyon veya türün yalnızca bir kez tanımlanmasını garanti eder. Bu kurala göre:

- Her global değişkenin yalnızca bir tanımı (`definition`) olabilir, ama birden çok bildirimi (`extern`) olabilir.
- Inline fonksiyonlar, constexpr fonksiyonlar ve template yapılar tüm çeviri birimlerinde aynı olmak koşuluyla tekrar tanımlanabilir.
- Sınıf tanımları, tüm çeviri birimlerinde birebir aynı olmalıdır.

Bu kuralların ihlali genellikle derleyici veya bağlayıcı hatalarına yol açar.

📂 `one_definition_rule/` klasöründe örnekler yer almaktadır.

C++ için temel kavramlar üzerine konuşmaya devam edelim. Tek tanımlama kuralı - One Definition Rule üzerine konuşalım. 

📄 C++'de Tek Tanımlama Kuralı (One Definition Rule - ODR), bir nesnenin, fonksiyonun veya türetilmiş bir tipin (class, struct, enum vb.) program içinde yalnızca bir tanımının olmasını gerektirir. Bu kural, derleyicinin birden fazla tanımlamadan kaynaklanan çakışmaları önlemesine yardımcı olur.

🔍 ODR'nin temel prensiplerinden ilki, değişken ve fonksiyon tanımları ile ilgilidir. Bir değişken veya fonksiyonun bir programda yalnızca bir kez tanımlanması gerekir, ancak birden fazla dosyada bildirimi yapılabilir. Bildirimler (extern gibi) kullanılarak birden fazla çeviri biriminde erişim sağlanabilirken, tanım yalnızca tek bir çeviri biriminde bulunmalıdır.

🔍İkinci prensip, inline fonksiyonlar, constexpr fonksiyonlar ve şablonlar ile ilgilidir. Bu yapılar, her çeviri biriminde aynı olacak şekilde birden fazla tanımlanabilir, ancak içeriklerinin birebir aynı olması şarttır. Örneğin, bir inline fonksiyon veya template fonksiyonu birden fazla çeviri biriminde tanımlanabilir, ancak tanımlar arasında herhangi bir farklılık olması ODR ihlaline yol açar.

🔍Üçüncü prensip ise sınıflar ve türler için geçerlidir. Bir class, struct, union veya enum, farklı çeviri birimlerinde tekrar tanımlanabilir ancak birebir aynı olması zorunludur. Eğer aynı isimde ancak farklı içerikte bir sınıf tanımlanırsa, derleyici veya bağlayıcı aşamasında hata oluşur. Bu kuralların ihlali genellikle çoklu tanımlama hatalarına (multiple definition error) veya tanımsız davranışa yol açar. ODR’nin sağlanması için header dosyalarında hashtag#pragma once veya hashtag#ifndef gibi mekanizmalar, değişkenlerde extern, fonksiyonlarda inline kullanımı yaygın bir uygulamadır.

📂 Aşağıdaki görselde Tek Tanımlama Kuralı (ODR)'nin nasıl uygulandığı gösterilmektedir; farklı çeviri birimlerinde (file1.cpp ve file2.cpp) değişkenlerin, inline fonksiyonların ve sınıfların doğru şekilde tanımlanması sağlanarak olası ODR ihlalleri önlenmiştir.