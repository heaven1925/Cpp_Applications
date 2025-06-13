/*
    Polymorpism, bir nesne'nin pointer'ı farklı nesne tipini göstermek isteniyorsa Polymorpism kullanılır.
    
    Bu yöntem için sınıflar arası inheretence olmalıdır.
    
    Üst sınıftan yaratılan pointer, farklı nesneleri gösterebilir. Bu sayede dinamik bir şekilde çağırılıyor.
    
    Ana sınıfta tanımlanan fonksiyonlar aynı şekilde üst sınıfta da tanımlanması gerekmektedir.
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    Overwriting olmadan Polymorpism yapılamaz. Bu fonksiyonlar virtual tanımlanmalidir.
    
*/


#include <iostream>

using namespace std;

#define VIRTUAL

class A
{ /* Üst sınıf */
    public:
    #ifdef VIRTUAL
        virtual 
    #endif
    void print(){ cout << "A" << endl; }
};


class B:public A
{ /* Alt sınıf */
    public:
        void print(){ cout << "B" << endl; }
};


class C:public A
{ /* Alt sınıf */
    public:
        void print(){ cout << "C" << endl; }
};


int main()
{
    ////////////////////////////////////////////////////////////////////////////////////////////////
    /* üst sınıf tipinde tanımlanan pointer'ın alt sınıf tipinde bir nesneyi göstermesi */
    A* pA = new B;
    pA->print(); /* A'yı yazıyor . */
    pA = new C;
    pA->print(); /* A'yı yazıyor . */
    /* pointer'ın sadece A sınıfına erişimi olduğu için sadece onu yazıyor */
    delete pA;
    ////////////////////////////////////////////////////////////////////////////////////////////////
    
    /* Bu sebeple polymorpism ile sanal fonksiyon kullanılmalıdır. */
    
    
    
    return 0;
}