#include <iostream>
#include <map>
#include <vector>
#include <string>

int main() {
    std::map<std::string, std::vector<int>> myMap;
    myMap["example"] = {1, 2, 3};

    // 😵‍💫 Geleneksel kullanım:
    std::map<std::string, std::vector<int>>::iterator it1 = myMap.begin();

    // 😌 auto ile sadeleştirme:
    auto it2 = myMap.begin();

    std::cout << "First key: " << it2->first << "\n";
    return 0;
}
