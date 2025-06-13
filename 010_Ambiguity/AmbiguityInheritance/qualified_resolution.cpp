#include <iostream>

class Logger {
public:
    void init() {
        std::cout << "Logger initialized\n";
    }
};

class Config {
public:
    void init() {
        std::cout << "Config initialized\n";
    }
};

class System : public Logger, public Config {
public:
    void initializeAll() {
        Logger::init();  // ✅ Belirterek ambiguity çözülür
        Config::init();
    }
};

int main() {
    System sys;
    sys.initializeAll();
    return 0;
}
