/*

    Dinamik bir dizi gibi çalışmaktadır. Bellekte arka arkaya tutar.
    
    - Dizinin aksine eleman sayısını belirlemeye gerek yoktur.
    - Yeni eleman eklendiğinde otomatik genişler
    - Kaç tane eleman tuttuğunu saklar
    
    
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> test(6,4); /* 6 elemanlı her elemanını 4 atandı */
    
    test[0] += 5;
    test[1] -= 2;
    
    for( int i = 0 ; i < 6 ; i ++)
    {
        cout << "test["<< i <<"]=" << test.at(i) << endl;
    }

    vector <int> x,y;
    
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    
    cout << x.front() << endl;
    cout << x.back() << endl;
    cout << x.size() << endl;
    cout << x.empty() << endl;



    return 0;
}