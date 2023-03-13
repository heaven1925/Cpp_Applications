/*

Friend Class

*/

#include <iostream>

using namespace std;


class B;

class A{
    
    int a;
    
    public:
        A(int _a){ a = _a; }
        /* Friend Class Tanımlanması*/
        friend class B;
};

class B{
    int b;
    public:
        B(int _b){ b = _b; }
        /* Bu fonksiyon A class'ı icin b üzerinden kullaniliyor. */
        void print( A &aHandle );
};


void B::print( A &aHandle )
{
    cout << aHandle.a << endl;
}


int main()
{
    A a1(25);
    B b1(12);
    
    /* b1 objesi üzerinden a1 classında tanımlanan a nesnesi yazildi. */
    b1.print(a1);

    return 0;
}