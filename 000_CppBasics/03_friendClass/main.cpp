/*
    Friend Function ve Friend class
    
    -> Sınıflar arası 4 farklı ilişki olabilir.
    
1- Birbirinden bağımsız olabilir
2- Miras yoluyla ilişkilendirilmiş olabilir.
3- Friend yoluyla baglanabilir.
4- Bi sınıf başka bir sınıfın nesnesi olabilir ( Composition )
    
*/


#include <iostream>

using namespace std;

class substract
{
    /* etiket altında tanımlanmayan uyeler private'dır */
    int a;
    int b;
public:
    /* constructor */
    substract(int _a, int _b) { a = _a;  b = _b; }
    /* friend function prototype */
    friend int print(substract &sub);
};

/* Friend function definition */
int print(substract &sub)
{
    return ( sub.a - sub.b);
}


int main()
{
    
    substract subResult(10,5);
    
    cout << print(subResult) << endl;
    

    return 0;
}