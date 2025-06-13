/*
    OOP( Object Oriented Programming )
    
    Class kavramD1, OOP ProgramlamanD1n temel kavramD1dD1r.
    
    Encouplation, veri ve bu veri ile ilgili iElemlerin tek bir veri yapD1sD1nda toplanmasD1 gerektiDini anlatD1r.
    
    Class, yapD1lacak iEleme gC6re deDiEkenleri ve fonksiyonlarD1 tanD1mlayan yapD1dD1r.
    Bu class'larD1n data-member ve method'larD1 mevcuttur.
    Class'ta data-member'lara farklD1 eriEim etiketleriyle ulaED1labilir ( public - private - protected )

    * public -> Genel, dD1ED1rdan programD1n her yerinden ulaED1labilir;
    * private -> Sadece sD1nD1f iC'erisinden eriEilebilir. ( Bir iletiEim aracD1 fonksiyon vb. ile eriEilebilir. )
    * protected -> Cst sD1nD1flardan miras alD1ndD1DD1 zaman kullanD1lmaktadD1r.

    Class ismi aynD1 zamanda bir veri tipidir. Bu doDrultuda bir yer aC'D1lmaz. 

    Bir tane prototip sD1nD1fdan birden fazla oluEturulabilir.
    
    (::) Binary scop resolution operator
*/

#include <iostream>

using namespace std;

class testBeef
{
public:
  int x;
   /* Satır ici inline fonksiyonlar kısa oldukları icin sınıf içinde yazılabilir. */
  void printX (){ cout << "x : " << x << endl; };
  /* Sınıfa ait fonksiyonun prototipi */
  void attach (int x);

private:
  int y = 5 ;
  void printY(){ cout << "y : " << y << endl; };
};


void
testBeef::attach (int x)
{
  y = this->x;
  this->x = x;
  printY();
}

int
main ()
{
  /* Class tanımlaması */
  testBeef test;

  /* Class Public degiskene erisim */
  test.x = 10;
  test.printX ();
  
  /* Change new value X and old value X=Y */
  test.attach (20);
  test.printX ();

  return 0;
}
