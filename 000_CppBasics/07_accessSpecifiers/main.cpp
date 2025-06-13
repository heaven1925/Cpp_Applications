/*

Access specifiers - Erişim belirteçleri

Bir class içerisinde;

public  -> Miras ilişkisinden bağımsız şekilde diğer tüm sınıflar tarafından erişebilir. 
private -> Bu tiptekileri sadece sınıfın üyeleri kullanabilir.
protected -> private gibidir ancak sadece alt sınıflar erişebilir.

*/


#include <iostream>

using namespace std;

/* Miras alınacak ana class'ı oluşturalım */
class A
{
  private:
    int a;
    
  public:
    int b;
    
    void    setA(int a){ this->a = a; }
    int     getA(){ return a; }
    void    setB(int b){ this->b = b; }
    int     getB(){ return b; }
    void    setC(int c){ this->c = c; }
    int     getC(){ return c; }
    
  /* üst sınıf tarafından erisilmesi istenen degisken */
  protected:
    int c;

};

/* A sınıfından B sınıfı türetiliyor. */
class B:public /* buraya private ve protected'ta yazılabilir */ A
{
  public:
    void print()
    {
        cout << "a:" << getA() << endl;
        cout << "b:" << getB() << endl;
        cout << "c:" << getC() << endl;
    }
};



int main()
{

    B b1;
    
    b1.setA(1);
    // b1.setB(2);  public oldugu icin erisilemez ! 
    b1.setC(3);
    b1.print();
    
    cout << endl;
    
    /* b1 class'ına doğrudan erişim yaparak erişilebilir. */
    //b1.a = 11;
    b1.b = 22;
    //b1.c = 33;
    b1.print();

    return 0;
}