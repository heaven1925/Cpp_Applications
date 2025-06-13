#include <iostream>

class Motor {
private:
    int speed; // class scope

public:
    void setSpeed(int s) {
        speed = s; // this->speed ile aynı
    }

    void print() {
        std::cout << "Speed: " << speed << std::endl;
    }
};

int main() {
    Motor m;
    m.setSpeed(100);
    m.print();
    return 0;
}
