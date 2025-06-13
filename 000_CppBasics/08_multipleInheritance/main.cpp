/*

Multiple inheretese , bi class birden fazla class'a ait özellikleri miras alabilir.

*/

#include <iostream>

using namespace std;


class A
{
    int a;
public:
    int getA(){ a=2; return a;}
};

class B
{
    int b;
public:
    int getB(){ b=3; return b; }
};

class X:public A, public B
{
    int x;
public:
    int getX(){ x = 4  ; return x;}
};


int main()
{
    X x1;
    
    cout << "A : " << x1.getA() << endl;
    cout << "B : " << x1.getB() << endl;
    cout << "X : " << x1.getX() << endl;
    
    
    return 0;
}