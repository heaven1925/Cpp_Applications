/*

    // , / , :: ?: gibi operatorler overload edilemez.
    
    Varolan 2 class arasında işlemler gerçekleştirmek amacıyla
    operatorler yeniden anlamlandırılması gerekmektedir.
    
    Class içerisinde bir fonksiyon olarak yazmak gerekmektedir. ( Operator function )
    
*/

#include <iostream>

using namespace std;

class test 
{
  int x;
  
  public:
  test(int _x){ x = _x; }
  /* Operator function */
  void operator *(){ this->x = this->x * 5; };
  /* Print function */
  void print(){ cout << this->x << endl; }
};


int main()
{
    test t1(5);
    t1.print();
    /* operator overloading */
    *t1;
    t1.print();
    

    return 0;
}