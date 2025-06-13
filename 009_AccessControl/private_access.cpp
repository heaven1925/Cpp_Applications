#include <iostream>

class Motor {
private:
    int speed = 0;

public:
    void SetSpeed(int s) {
        if (s >= 0 && s <= 100)
            speed = s;
    }

    void PrintSpeed() {
        std::cout << "Speed: " << speed << std::endl;
    }
};

int main() {
    Motor m;
    m.SetSpeed(80);
    m.PrintSpeed();
    // m.speed = 200; ❌ hata: private üyeye doğrudan erişilemez
    return 0;
}
