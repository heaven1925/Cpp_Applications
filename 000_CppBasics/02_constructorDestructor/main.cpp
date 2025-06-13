/*
    Constructor : Yapıcı fonksiyonlar , nesneye ilk değer atamak amacıyla kullanılırlar.
    Destructor : Yıkıcı fonksiyonlar , nesne yok olmadan önce değerlerini temizlemek için kullanılır.

    Constructor ile nesne istenilen değerlerle yaratılmaktadır.

    /* Aynı sınıf tipinde başka bir nesneyi parametre alan constructorlara copy constructor denir 

*/


#include <iostream>

using namespace std;

class sum
{
    public:
        /* contructor ismi class ismi ile aynı olmalıdır. */
        sum( int _x , int _y ){ x = _x; y = _y; }
        /* copy constructor */
        sum( sum &sum1 );
        /* Destructor */
        ~sum();
        /* sınıf için private degiskenlere this-> etiketiyle erişilir */
        int result() { return this->x + this->y; }
        
    private:
        int x;
        int y;
};

sum::~sum()
{
    cout << "Destructor" << endl;
    /* Destructor fonksiyonlar overload edilemez ! */
    this->x = 0;
    this->y = 0;
}

sum::sum( sum &sum1 )
{
    this->x = sum1.x;
    this->y = sum1.y;
}


int main()
{
    sum testSum1(5,2);
    cout << testSum1.result() << endl ;
    
    sum testSum2(7,8);
    cout << testSum2.result() << endl ;
    
    /* Copy Constructor */
    sum testSum3(testSum2);
    cout << testSum2.result() << endl ;

    return 0;
}