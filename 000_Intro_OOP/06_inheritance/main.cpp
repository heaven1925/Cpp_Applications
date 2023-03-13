/******************************************************************************

Inheretence, (miras , kalıtım) :

Varolan bir sınıftan, başka bir sınıf daha üretilip, alt sınıfa aktarılmasına denir.
Sınıflar arası hiyerarşi kurulmasını sağlar. 

Bu sayede kod tekrarı ortadan kalkar.

Ana sınıftan türeyen bu sınıflar miras yoluyla bu değişkenlere sahip olurlar.

*Özellikleri miras alınan class'a üst class, baseclass - superclass denir
 
*Türetilen class'a ise alt class , subclass , derived class denir.
 
 Aralarında miras ilişkisi bulunan alt sınıf, üst sınıfın üyelerini kapsar.
 Üst sınıf, alt sınıfa ait üyelere erişemez.
 
 Inheretence kavramı işlenirken protected erişim etiketi kullanılır.
 Protected üyeler miras aldığı class'a 
 
*******************************************************************************/
#include <iostream>

using namespace std;

/* Miras alınacak ana class'ı oluşturalım */
class A
{
  private:
    int a;
  public:
    void    setA(int a){ this->a = a; }
    int     getA(){ return a; }
};

/* A sınıfından B sınıfı türetiliyor. */
class B:public A
{
  private:
    int b;
  public:
    void    setB(int b){ this->b = b; }
    int     getB(){ return b; } 
};


int main()
{
    B b1;
    
    b1.setB(10);
    cout << b1.getB() << endl;
    
    b1.setA(20);
    cout << b1.getA() << endl;
    

    return 0;
}